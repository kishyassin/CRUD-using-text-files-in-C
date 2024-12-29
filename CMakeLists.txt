cmake_minimum_required(VERSION 3.29)
project(crud)

set(CMAKE_CXX_STANDARD 20)

add_executable(crud source/main.cpp
        source/logic/crud.cpp
        source/logic/crud.h
        source/index/index.h
        source/index/index.cpp)
