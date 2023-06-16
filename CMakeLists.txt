cmake_minimum_required(VERSION 3.25)
project(Calculator)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_COMPILER "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\Llvm\\bin\\clang-cl.exe")
set(CMAKE_CXX_COMPILER "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\Llvm\\bin\\clang-cl.exe")

add_executable(Calculator main.cpp Calculation.cpp Calculation.hpp)



