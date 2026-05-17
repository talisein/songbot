#!/usr/bin/env python3
import subprocess, sys

input_file = sys.argv[1]
output_file = sys.argv[2]
fallback_version = sys.argv[3]

def escape_cpp(s):
    return s.replace('\\', '\\\\').replace('"', '\\"')

try:
    git_hash = subprocess.check_output(['git', 'log', '-1', '--format=%h'], text=True).strip()
except Exception:
    git_hash = fallback_version

try:
    git_msg = subprocess.check_output(['git', 'log', '-1', '--format=%s'], text=True).strip()
except Exception:
    git_msg = ''

with open(input_file) as f:
    content = f.read()

content = content.replace('PROJ_VERSION', escape_cpp(git_hash))
content = content.replace('PROJ_COMMIT_MSG', escape_cpp(git_msg))

try:
    with open(output_file) as f:
        if f.read() == content:
            sys.exit(0)
except FileNotFoundError:
    pass

with open(output_file, 'w') as f:
    f.write(content)
