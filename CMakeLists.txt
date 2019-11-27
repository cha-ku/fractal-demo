cmake_minimum_required(VERSION 2.6)
project(fractal_demo)
add_executable(fractal_demo main.cpp BitMapFileHeader.hpp BitMapInfoHeader.hpp BitMap.cpp BitMap.hpp Mandelbrot.cpp Mandelbrot.hpp)
install(TARGETS fractal_demo RUNTIME DESTINATION bin)
