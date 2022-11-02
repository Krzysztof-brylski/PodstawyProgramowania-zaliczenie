cmake_minimum_required(VERSION 3.23)
project(labKodowanieEz5)

set(CMAKE_CXX_STANDARD 20)
add_executable(labKodowanieEz5 main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static")