#!/bin/bash
# Xiang Wang(ramwin@qq.com)

set -e

echo "LLVM安装路径: $LLVM_DIR"

cd $LLVM_DIR
cmake --build . -j
cd -

$LLVM_DIR/bin/clang -O0 -Xclang -disable-O0-optnone -S -emit-llvm ./input.c -o ./input.ll
echo "编译完成"
# $LLVM_DIR/bin/opt --passes=loop-data-prefetch ./input.ll -o ./optimized.ll
# $LLVM_DIR/bin/opt ./input.ll -o ./optimized.ll
echo "优化完成"
# $LLVM_DIR/bin/lli ./optimized.ll
$LLVM_DIR/bin/lli ./input.ll
echo "执行完成"
