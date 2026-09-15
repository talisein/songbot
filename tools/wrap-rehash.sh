#!/usr/bin/env bash
#
# Finish a Renovate wrap bump.
#
# Renovate has no meson manager, so subprojects/*.wrap is covered by custom
# regex managers in renovate.json5. Those rewrite only the span they matched --
# the version inside source_url -- and they cannot compute a sha256 at all.
# This script reconciles the rest of each [wrap-file]: the version inside the
# source_url's filename, source_filename, directory, and source_hash. It is
# wired up through postUpgradeTasks.
#
# Run from anywhere; it locates the repository root itself. Exits non-zero on
# ANY failure. That does NOT abandon the branch -- read renovate's
# execute-post-upgrade-commands.js: a throwing command is caught and pushed
# onto artifactErrors, and the PR is opened regardless, carrying an artifact
# warning and the PREVIOUS source_hash. A wrong hash is not a soft failure --
# meson refuses at `setup`, before a line compiles -- so the alarm that
# actually catches it is .forgejo/workflows/pr-build.yml failing on the PR,
# with the artifact warning in the PR body saying why.
#
# Idempotent -- `--all` on an unmodified tree re-downloads every wrap, hashes
# to the value already on disk, and rewrites each file byte-identically.
#
# Needs curl, sha256sum, sed and awk. Deliberately no python and no meson:
# this runs inside the Renovate container, not the songbot SDK image.

set -euo pipefail

cd "$(dirname "$0")/.."

# Only touch wraps this branch actually changed. postUpgradeTasks runs on EVERY
# renovate branch, fedora and container bumps included, and executionMode is
# 'branch' -- so without this gate an unrelated PR would re-download every
# tarball, and a github outage during one would abort a PR that has nothing to
# do with github.
#
# Renovate writes the updated files before running this, so a diff against HEAD
# is exactly "what this branch changed". `--all` forces the full pass; that is
# what to use when verifying by hand, since a clean tree has no diff and would
# otherwise short-circuit before proving anything.
targets=()
if [ "${1:-}" = "--all" ]; then
    targets=(subprojects/*.wrap)
elif changed="$(git diff --name-only HEAD -- 'subprojects/*.wrap' 2>/dev/null)"; then
    if [ -z "$changed" ]; then
        # Announced rather than silent. This gate assumes renovate runs
        # postUpgradeTasks BEFORE committing -- which is what fileFilters
        # implies, since it selects which CHANGED files get committed. If that
        # ever stops holding, every wrap PR would skip the rehash and this line
        # is the only thing in the log that would say so.
        echo "wrap-rehash: no wrap changes against HEAD; nothing to do" >&2
        exit 0
    fi
    while IFS= read -r f; do
        [ -n "$f" ] && targets+=("$f")
    done <<< "$changed"
else
    # No usable git (not a checkout, no HEAD yet). Fall back to every wrap
    # rather than silently doing nothing -- a redundant download is cheap and a
    # skipped rehash is not.
    targets=(subprojects/*.wrap)
fi

tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT

status=0

for wrap in "${targets[@]}"; do
    [ -e "$wrap" ] || continue

    url="$(sed -n 's/^[[:space:]]*source_url[[:space:]]*=[[:space:]]*\(.*[^[:space:]]\)[[:space:]]*$/\1/p' "$wrap")"

    # [wrap-git] has no tarball and therefore no hash to fix. boostut is
    # tracked by Renovate all the same -- it just needs nothing from here.
    if [ -z "$url" ]; then
        continue
    fi

    if [ "$(printf '%s\n' "$url" | wc -l)" -ne 1 ]; then
        echo "wrap-rehash: $wrap: expected exactly one source_url" >&2
        status=1
        continue
    fi

    # The version Renovate just wrote. Both URL shapes in this repo carry it as
    # a v-prefixed path component:
    #   /releases/download/v<ver>/...        (dpp, json, prometheus-cpp)
    #   /archive/refs/tags/v<ver>.tar.<ext>  (magic_enum, uni-algo)
    ver="$(printf '%s' "$url" | sed -n \
        -e 's#.*/releases/download/v\([0-9][^/]*\)/.*#\1#p' \
        -e 's#.*/archive/refs/tags/v\([0-9][^/]*\)\.tar\..*#\1#p' \
        | head -n1)"

    if [ -z "$ver" ]; then
        echo "wrap-rehash: $wrap: no version found in source_url: $url" >&2
        status=1
        continue
    fi

    # REPAIR THE URL BEFORE FETCHING IT. Renovate replaces only the span its
    # matchString matched -- the `/v<ver>/` path component -- so for a release
    # whose asset name also carries the version it leaves the two halves
    # disagreeing:
    #   .../releases/download/v10.1.7/DPP-10.1.6.tar.gz   <- 404
    # Rewriting the version inside the BASENAME only, and never inside the
    # path, brings it back in line. The other two release wraps have
    # version-free basenames (json.tar.xz,
    # prometheus-cpp-with-submodules.tar.gz) and are untouched, and for the
    # archive/refs/tags shape the basename IS the version renovate just wrote,
    # so the substitution is a no-op there.
    base="${url##*/}"
    url="${url%/*}/$(printf '%s' "$base" | sed -E "s/[0-9]+(\.[0-9]+)+/$ver/")"

    dl="$tmp/$(basename "$wrap").tar"
    if ! curl -fsSL --retry 3 --retry-delay 2 -o "$dl" "$url"; then
        echo "wrap-rehash: $wrap: download failed: $url" >&2
        status=1
        continue
    fi

    hash="$(sha256sum "$dl" | cut -d' ' -f1)"

    out="$tmp/$(basename "$wrap").new"
    if ! VER="$ver" HASH="$hash" URL="$url" awk '
        BEGIN { ver = ENVIRON["VER"]; hash = ENVIRON["HASH"]; url = ENVIRON["URL"]; seen_hash = 0 }
        {
            line = $0

            # Written back whether or not it changed: the repaired form is the
            # one that was actually downloaded and hashed, so the file must
            # agree with it.
            if (match(line, /^[ \t]*source_url[ \t]*=[ \t]*/)) {
                print substr(line, 1, RLENGTH) url
                next
            }

            if (match(line, /^[ \t]*source_hash[ \t]*=[ \t]*/)) {
                seen_hash = 1
                print substr(line, 1, RLENGTH) hash
                next
            }

            if (match(line, /^[ \t]*(source_filename|directory)[ \t]*=[ \t]*/)) {
                head = substr(line, 1, RLENGTH)
                val  = substr(line, RLENGTH + 1)
                sub(/[ \t]+$/, "", val)
                # Only version-BEARING values are touched. json.wrap has
                # `directory = json` and prometheus-cpp.wrap has
                # `directory = prometheus-cpp-with-submodules`; neither carries
                # a version and both must survive a bump unchanged. A blanket
                # old->new substitution over the whole file would be wrong for
                # exactly these two.
                sub(/[0-9]+(\.[0-9]+)+/, ver, val)
                print head val
                next
            }

            print line
        }
        END { if (!seen_hash) exit 1 }
    ' "$wrap" > "$out"; then
        echo "wrap-rehash: $wrap: has source_url but no source_hash" >&2
        status=1
        continue
    fi

    mv "$out" "$wrap"
done

exit "$status"
