#include <iostream>
#include "../Stack/stack.hpp"

/*
 * Post:  The program has notified the user of any bracket mismatch in the 
 *        standard input file.
 * Usess: The class Stack
 */
int main()
{

  Stack openings;
  char symbol {};
  bool is_matched {true};
  while (is_matched && (symbol = std::cin.get()) != '\n') {
    if (symbol == '{' || symbol == '(' || symbol == '[') {
      openings.push(symbol);
    } else if (symbol == '}' || symbol == ')' || symbol == ']') {
      if (openings.empty()) {
        std::cout << "Unmatched closing bracket " << symbol
          << " detected.\n";
        is_matched = false;
      } else {
        char match;
        openings.top(match);
        openings.pop();
        is_matched =  (symbol == '}' && match == '{') ||
          (symbol == ')' && match == '(') ||
          (symbol == ']' && match == '[');
        if (is_matched) {
          std::cout << "Bad match " << match << symbol << '\n';
        }
      }
    }
  }
  if (!openings.empty()) {
    std::cout << "Unmatched opening bracket(s) detected.\n";
  }
}
