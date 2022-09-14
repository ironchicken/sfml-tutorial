cmake_minimum_required(VERSION 3.22)

project(sfml_tutorial)

set(simple_VERSION_MAJOR 0)
set(simple_VERSION_MINOR 1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(vendor)
add_subdirectory(src)
