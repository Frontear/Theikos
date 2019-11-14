cmake_minimum_required(VERSION 3.15)
project(Theikos)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-lGL -lGLEW -lglfw")

add_executable(Theikos src/main.cpp src/theikos/display.cpp src/theikos/display.h src/theikos/internal/opengl.h)