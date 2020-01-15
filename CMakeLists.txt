cmake_minimum_required(VERSION 3.14)
project(AP)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP main.cpp ap.h ap.cpp Pilha.h Pilha.cpp)