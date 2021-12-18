#!/bin/bash
# Xiang Wang(ramwin@qq.com)


cd ..
if [ ! -d "Step2_build" ];
then
    mkdir Step2_build
fi
cd Step2_build
cmake ../Step2 -DUSE_MYMATH=ON
cmake --build .

./Tutorial
./Tutorial 9

cmake ../Step2 -DUSE_MYMATH=OFF
cmake --build .

./Tutorial
./Tutorial 9
