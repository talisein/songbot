#!/usr/bin/env bash
#
# Build one wrap's meson overlay standalone and install it into /usr, with its
# srchash recorded in the .pc files it generates. Run by the songbot-sdk build
# in .forgejo/workflows/sdk-update.yml, from a directory holding subprojects/
# (wraps and packagefiles) and tools/. meson.build uses the installed copy
# only while that srchash matches the checkout; see there.
#
# The overlay has to take a `srchash` option and, when not a subproject,
# install itself and write .pc files (packagefiles/dpp/meson.build is the
# example).
#
# --prefix=/usr because /usr/local/lib64/pkgconfig is not on Fedora's
# pkg-config path.
#
# Usage: tools/sdk-install-subproject.sh NAME

set -euo pipefail

cd "$(dirname "$0")/.."
name=$1
hash=$(tools/srchash.sh "$name")
dir=$(sed -n 's/^directory *= *//p' "subprojects/$name.wrap")
[ -n "$dir" ] || { echo "no directory = in subprojects/$name.wrap" >&2; exit 1; }

# 'meson subprojects download' refuses to run without a root meson.build.
# It extracts the wrap and applies the patch_directory overlay.
[ -f meson.build ] || echo "project('sdk-stub')" > meson.build
meson subprojects download "$name"

build=$(mktemp -d)
meson setup "$build" "subprojects/$dir" --prefix=/usr -Dsrchash="$hash"
meson install -C "$build"
rm -rf "$build" "subprojects/$dir"
