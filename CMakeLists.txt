cmake_minimum_required(VERSION 2.6)
project(fractal_demo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -O0")
add_executable(fractal_demo main.cpp BitMapFileHeader.hpp BitMapInfoHeader.hpp BitMap.cpp BitMap.hpp)

install(TARGETS fractal_demo RUNTIME DESTINATION bin)
