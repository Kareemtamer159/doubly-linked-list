cmake_minimum_required(VERSION 3.28)
project(Ds_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ds_project main.cpp
        file.h
        "Doubly linked list.cpp")
