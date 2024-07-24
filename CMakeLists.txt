cmake_minimum_required(VERSION 3.22)
project(RecordFileSystem)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(RecordFileSystem)

add_executable(ReactorServer main.cpp
        )