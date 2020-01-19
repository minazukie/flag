cmake_minimum_required(VERSION 3.15)
project(flag C)

set(CMAKE_C_STANDARD 11)

add_executable(flag flag.c flag.h main.c)