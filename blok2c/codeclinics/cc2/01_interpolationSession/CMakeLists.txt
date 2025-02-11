cmake_minimum_required(VERSION 3.20)
project(CMakeTestProject LANGUAGES CXX)

add_executable(interpolate main.cpp)
target_compile_features(interpolate PRIVATE cxx_std_20)