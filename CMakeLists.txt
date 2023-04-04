cmake_minimum_required(VERSION 3.23)
project(Currency-Converter-File)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Currency-Converter-File
        Convert.cpp
        Convert.h
        main.cpp
        NumberList.txt
        README.md)
add_executable(test testing.cpp Convert.cpp Convert.h)
