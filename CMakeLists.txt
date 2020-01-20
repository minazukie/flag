cmake_minimum_required(VERSION 3.15)
project(flag C)

set(CMAKE_C_STANDARD 11)

#dependencies
include_directories("vendor/uthash/include")
#dependencies end

add_executable(flag flag.c flag.h flag_test.c)