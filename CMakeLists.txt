cmake_minimum_required(VERSION 3.29)
project(HoffmanAlgorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HoffmanAlgorithm
    Node.cpp
    Node.h
        main.cpp
        HoffmanTree.cpp
        benchmark.cpp
        HoffmanTree.h
        writing.cpp
        writing.h
        BMPImages.cpp
        BMPImages.h
        writing.cpp
)
