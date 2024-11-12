cmake_minimum_required(VERSION 3.20)
project(CMakeTestProject LANGUAGES CXX)

add_executable(CMakeTestProject main.cpp ciska.cpp)
target_compile_features(CMakeTestProject PRIVATE cxx_std_20)
