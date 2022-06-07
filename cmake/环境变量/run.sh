#!/bin/bash
# Xiang Wang(ramwin@qq.com)

set -e
export RAMWIN="from_run"
if [ -d "build" ];
then
    rm -rf build
fi
mkdir build

cd build

cmake ../
cmake --build .

./Tutorial
