cmake_minimum_required(VERSION 3.30)
project(BigInt)

set(CMAKE_CXX_STANDARD 20)

add_executable(BigInt main.cpp
        BigInt.h
        BigInt.cpp)
