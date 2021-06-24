#include "../stack/stack.hpp"
#include <iostream>

void introduction() {
}

void instructions() {
}

char get_command() {
  char command {};

  bool waiting {true};
  while (waiting) {
      std::cout << "Select command and press <Enter>: ";
    std::cin >> command;
    command = tolower(command);
    switch (command) {
      case '?':
      case '=':
      case '+':
      case '-':
      case '*':
      case '/':
      case 'q':
        waiting = false;
        break;
      default:
        std::cout << "Please enter a valid command:\n"
          << "[?] push to stack  [=] print top\n"
          << "[+][-][*][/] are arithmetic operations\n"
          << "[Q]uit.\n";
    }
  }
  return command;
}

/*
 * Pre:   The first parameter specifies a valid calculator command.
 * Post:  The command specified by the first parameter has been applied 
 *        to the Stack of numbers given the second parameter. A result of
 *        true is returned unless the command indicates to quit.
 * Uses:  The class Stack
 */
bool do_command(char command, Stack &numbers) {
  double p {};
  double q {};
  bool finished {};
  switch (command) {
    case '?':
      std::cout << "Enter a real number: ";
      std::cin >> p;
      if (numbers.push(p) == Error_code::OVERFLOW) {
        std::cerr << "Warning: Stack full, lost number\n";
      }
      break;
    case '=':
      if (numbers.top(p) == Error_code::UNDERFLOW) {
        std::cerr << "Stack empty\n";
      } else {
        std::cout << p << '\n';
      }
      break;
    case '+':
      if (numbers.top(p) == Error_code::UNDERFLOW) {
        std::cerr << "Stack empty\n";
      } else {
        numbers.pop();
        if (numbers.top(q) == Error_code::UNDERFLOW) {
          std::cout << "Stack has just one entry\n";
          numbers.push(p);
        } else {
          numbers.pop();
          if (numbers.push(q + p) == Error_code::OVERFLOW) {
            std::cerr << "Warning Stack full, lost result\n";
          }
        }
      }
      break;
    case 'q':
      std::cout << "Calculation finished.\n";
      finished = true;
      break;
  }
  return finished;
}

/*
 * Post:  The program has executed simple arithmetic commands
 *        entered by the user.
 * Uses:  The class Stack and the functions introduction, instructions,
 *        do_command, and get_command
 */
int main()
{
  Stack stored_numbers;
  introduction();
  instructions();
  while (do_command(get_command(), stored_numbers)) {
  };
}
