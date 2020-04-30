#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>

bool user_says_yes()
{
  int c {};
  bool initial_response {true};
  do {
    if (initial_response) {
      std::cout << "(y, n)? ";
    } else {
      std::cout << "Respond with either y or n: ";
    }
    do {
      c = std::cin.get();
    } while (c == '\n' || c == ' ' || c == '\t');
    initial_response = false;
  } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');

  return c == 'y' || c == 'Y';
}

#endif
