cmake_minimum_required(VERSION 3.29)
project(c_learn_demos)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/inc)

add_executable(c_learn_demo_03 main.cpp esp861.c)
