cmake_minimum_required(VERSION 3.19)
project(1C)

set(CMAKE_CXX_STANDARD 20)

add_executable(1C main.cpp Scanline.cpp Scanline.hpp Circle.cpp Circle.hpp Checker.cpp Checker.hpp)