#!/bin/zsh

# 查找当前目录（不包含子目录）下的可执行文件，并删除，但排除当前脚本自身
find . -maxdepth 1 -type f -perm -111 ! -name "clear_exec.sh" -exec rm -f {} \;

echo "可执行文件已删除"