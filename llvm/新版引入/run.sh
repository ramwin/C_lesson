#!/bin/bash
# Xiang Wang(ramwin@qq.com)

set -e

echo "LLVM安装路径: $LLVM_DIR"


if [ -f "optimized.ll" ];
then
    echo "optimized.ll存在"
    rm optimized.ll
fi

if [ -f "input.ll" ];
then
    echo "input.ll存在"
    rm input.ll
fi

if [ ! -d "build" ];
then
    mkdir build
fi
cd build
cmake ../
cmake --build .
$LLVM_DIR/bin/clang -O0 -Xclang -disable-O0-optnone -S -emit-llvm ../input.c -o ../input.ll

echo "\n优化开始\n"
$LLVM_DIR/bin/opt -S \
    -load-pass-plugin ./libRamwin.so \
    -passes=ramwin \
    -o ../optimized.ll \
    ../input.ll

# $LLVM_DIR/bin/opt -S \
#     -passes=loop-data-prefetch \
#     -pass-remarks=loop-data-prefetch \
#     -loop-prefetch-writes=0 \
#     -prefetch-distance=16 \
#     -min-prefetch-stride=16 \
#     -max-prefetch-iters-ahead=16 \
#     -o ../optimized.ll \
#     ../input.ll

echo "\n优化结束\n"
$LLVM_DIR/bin/lli ../optimized.ll
