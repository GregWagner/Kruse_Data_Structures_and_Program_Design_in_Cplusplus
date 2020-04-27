/*
 * Program to play Conway's Game of Life.
 */

#include "utility.hpp"
#include "life.hpp"
#include <iostream>

void instructions()
{

}

bool user_says_yes()
{
  return true;
}

int main()
{
  Life configuration;
  instructions();
  configuration.initialize();
  configuration.print();
  std::cout << "Continue viewing new generations? ";
  while (user_says_yes()) {
    configuration.update();
    configuration.print();
    std::cout << "Continue viewing new generations? ";
  }

}
