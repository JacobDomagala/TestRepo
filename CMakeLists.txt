cmake_minimum_required(VERSION 3.13)

project(Test)

add_executable(TestApp source.cpp)
target_compile_features(TestApp PRIVATE cxx_std_17)
