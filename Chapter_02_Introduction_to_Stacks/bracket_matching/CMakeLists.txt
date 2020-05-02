cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(matcher LANGUAGES CXX)

add_library(stack
  STATIC
    ../Stack/stack.hpp
    ../Stack/stack.cpp
  )

add_executable(matcher main.cpp)

target_link_libraries(matcher stack)
