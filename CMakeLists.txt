cmake_minimum_required(VERSION 3.27)
project(untitled42)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled42 main.cpp
        Register.h
        Control_Unit.h
        Machine.h
        Main_UI.h)
