cmake_minimum_required(VERSION 3.20)
project(CMakeTestProject LANGUAGES CXX)

add_executable(Hi hello.cpp)
target_compile_features(Hi PRIVATE cxx_std_20)