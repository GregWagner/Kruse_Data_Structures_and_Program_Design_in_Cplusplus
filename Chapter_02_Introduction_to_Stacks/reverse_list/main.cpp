#include <stack>
#include <iostream>

/*
 * Pre:   The user supplies an integer n and n decimal numbers.
 * Post:  The numbers are printed in reverse order
 * Uses:  The STL class stack and its methods
 */
int main() {
  std::stack<double> numbers;

  int n {};
  std::cout << "Type in an integer n followed by n decimal numbers.\n"
    << "The numbers will be printed in reverse order.\n";
  std::cin >> n;

  double item {};
  for (int i {}; i < n; ++i) {
    std::cin >> item;
    numbers.push(item);
  }
  std::cout << "\n\n";

  while (!numbers.empty()) {
    std::cout << numbers.top() << ' ';
    numbers.pop();
  }
  std::cout << '\n';
}
