cmake_minimum_required(VERSION 3.10)
project(UNIX-FILESYSTEM-TREE)
set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES ../src/*.c)

foreach(SOURCE ${SOURCES})
    message("Found source file: ${SOURCE}")
endforeach()

add_executable(UFT ${SOURCES})