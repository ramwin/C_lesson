#!/bin/bash

clang \
    -O1 \
    -S -emit-llvm \
    -o $1 \
    test_branch.c
