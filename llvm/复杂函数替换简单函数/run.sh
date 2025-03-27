#!/bin/bash
# Xiang Wang(ramwin@qq.com)

set -e

if [ ! -d "build" ];
then
    mkdir build
fi
cd build
cmake ../
cmake --build .
clang -O0 -Xclang -disable-O0-optnone -S -emit-llvm ../input.c -o ../input.ll
opt -S -load-pass-plugin ./libPrintInstruction.so -passes=print-instruction ../input.ll -o ../optimized.ll
lli ../optimized.ll
