#!/bin/bash
# Xiang Wang(ramwin@qq.com)

FILE=inline.c
clang -S -emit-llvm $FILE -o normal.ll
clang -S -emit-llvm $FILE -O1 -o o1.ll
clang -S -emit-llvm $FILE -finline -O1 -o inline.ll
vimdiff normal.ll o1.ll inline.ll 
