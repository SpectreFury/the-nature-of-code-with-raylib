
cmake_minimum_required(VERSION 3.10)

project(raylib)

include_directories(../../Dependencies/include/Vector)

add_library(vector ../../Dependencies/lib/Vector/vector.cpp)

add_executable(raylib main.cpp)

target_include_directories(raylib PRIVATE ../../Dependencies/include)

target_link_directories(raylib PRIVATE ../../Dependencies/lib)

target_link_libraries(raylib Raylib/raylib winmm vector)