cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(game_of_life LANGUAGES CXX)

add_executable(game_of_life 
  main.cpp
  life.cpp)
