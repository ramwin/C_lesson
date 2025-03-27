#!/bin/bash
# Xiang Wang(ramwin@qq.com)

FILENAME=simple.c
set -e

if [ ! -d "build" ];
then
    mkdir build
fi
cd build
cmake ../
cmake --build .
clang -Wall -Wextra -O0 -Xclang -disable-O0-optnone -S -emit-llvm ../$FILENAME -o ../input.ll
echo "编译完成"
opt -S -load-pass-plugin ./libPrintInstruction.so -passes=print-instruction ../input.ll -o ../optimized.ll
echo "优化完成"
lli ../optimized.ll
echo "执行完成"
