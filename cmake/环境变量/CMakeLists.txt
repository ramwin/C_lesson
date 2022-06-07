cmake_minimum_required(VERSION 3.10)

message("RAMWIN="$ENV{RAMWIN})
# set the project name

set(
    ENV{RAMWIN} "FROM_CMAKELIST"
)

message("RAMWIN="$ENV{RAMWIN})

project(Tutorial VERSION 2.3)


add_executable(Tutorial tutorial.c)

target_include_directories(
    Tutorial PUBLIC
    "${PROJECT_BINARY_DIR}"'
)
