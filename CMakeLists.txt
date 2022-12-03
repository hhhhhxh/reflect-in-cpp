cmake_minimum_required(VERSION 3.16)
project(rigid)
set(CMAKE_CXX_STANDARD 17)

FILE(GLOB SRC main.cpp reflect/*.h reflect/*.cpp utility/*.h)

add_executable(rigid ${SRC})

target_include_directories(
    rigid
    PUBLIC
    reflect
    utility
)