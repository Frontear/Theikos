cmake_minimum_required(VERSION 3.15)
project(Theikos)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-lGL -lGLEW -lglfw")

add_executable(Theikos src/main.cpp src/theikos/display.cpp src/theikos/display.h src/theikos/internal/opengl.h src/theikos/shader.cpp src/theikos/shader.h src/theikos/program.cpp src/theikos/program.h src/theikos/buffer.cpp src/theikos/buffer.h)