cmake_minimum_required(VERSION 3.27)
project(proyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(proyecto main.cpp
        src/Modelo/Cliente.cpp
        headers/Modelo/Cliente.h)
