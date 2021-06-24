/*
 * Program to play Conway's Game of Life.
 */

#include "utility.hpp"
#include "life.hpp"

/*
 * Pre:   None
 * Post:  Verifies that the method neightbor_count() is working
 * Uses:  The class Life and its method initialize()
 */
void test_neighbor_count() {
  Life configuration {};
  configuration.initialize();
  configuration.test_neighbor_count();
}

/*
 * Pre:   The user supplies an initial configuration of living cells.
 * Post:  The program prints a sequence of pictures showing the changes
 *        in the configuration of living cells according to the rules for
 *        the game of life.
 * Uses:  The class Life and its methods initialize(), print(), and update().
 *        The functions instructions(), user_says_yes()
 */
int main() {
  test_neighbor_count();

  Life configuration {};
  configuration.instructions();
  configuration.initialize();
  configuration.print();

  do {
    configuration.update();
    configuration.print();
    std::cout << "Continue viewing new generations? ";
  } while (user_says_yes());
}
