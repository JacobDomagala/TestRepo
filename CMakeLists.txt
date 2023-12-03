cmake_minimum_required(VERSION 3.13)

project(Test)

add_executable(TestApp source.cpp another_source.cpp)
target_include_directories(TestApp PUBLIC "lib")
target_compile_features(TestApp PRIVATE cxx_std_17)
