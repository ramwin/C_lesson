#!/bin/bash
# Xiang Wang(ramwin@qq.com)

set -e

echo "LLVM安装路径: $LLVM_DIR"

if [ ! -d "build" ];
then
    mkdir build
fi
cd build
cmake ../
cmake --build .
$LLVM_DIR/bin/clang -O0 -Xclang -disable-O0-optnone -S -emit-llvm ../input.c -o ../input.ll
$LLVM_DIR/bin/opt -S \
    -load-pass-plugin ./libPrintInstruction.so \
    -passes=print-instruction \
    -o ../optimized.ll \
    ../input.ll
$LLVM_DIR/bin/lli ../optimized.ll
