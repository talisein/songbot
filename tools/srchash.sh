#!/usr/bin/env bash
#
# Print the content hash of one wrap and its overlay: subprojects/NAME.wrap
# plus every file under subprojects/packagefiles/NAME/, paths included, so a
# renamed or added overlay file changes it too.
#
# One script for both sides of the songbot-sdk prebuilt-library check:
# tools/sdk-install-subproject.sh records this in the installed .pc file as
# `srchash`, and meson.build compares it with the checkout's to decide whether
# the SDK copy is current. Change it and every SDK copy goes stale until the
# next sdk-update.yml run, which is safe: stale means build from the wrap.
#
# Usage: tools/srchash.sh NAME   (from anywhere)

set -euo pipefail

cd "$(dirname "$0")/../subprojects"
name=$1
[ -f "$name.wrap" ] && [ -d "packagefiles/$name" ] || {
  echo "srchash.sh: no subprojects/$name.wrap with packagefiles/$name/" >&2
  exit 1
}
{
  echo "$name.wrap"
  find "packagefiles/$name" -type f | LC_ALL=C sort
} | xargs -d '\n' sha256sum | sha256sum | cut -d' ' -f1
