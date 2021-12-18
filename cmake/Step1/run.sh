#!/bin/bash
# Xiang Wang(ramwin@qq.com)

cd ..
if [ ! -d "Step1_build" ];
then
    mkdir Step1_build
fi
cd Step1_build
cmake ../Step1
cmake --build .

./Tutorial
./Tutorial 9
