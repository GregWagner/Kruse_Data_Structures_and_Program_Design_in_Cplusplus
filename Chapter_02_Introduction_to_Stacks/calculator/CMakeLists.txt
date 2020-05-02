cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(calculator LANGUAGES CXX)

add_library(stack
  STATIC
    ../Stack/stack.hpp
    ../Stack/stack.cpp
  )

add_executable(calculator calculator.cpp)

target_link_libraries(calculator stack)
