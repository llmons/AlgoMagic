#!/bin/zsh

# find exec file and remove except self("clear_exec.sh")
find . -maxdepth 1 -type f -perm -111 ! -name "clear_exec.sh" -exec rm -f {} \;

echo "exec removed"
