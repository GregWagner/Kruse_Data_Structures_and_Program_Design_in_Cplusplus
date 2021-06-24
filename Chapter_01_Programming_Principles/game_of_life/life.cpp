#include "life.hpp"
#include <iostream>

/*
 * Pre:   None
 * Post:  Instructions for using the Life program have been printed
 */
void Life::instructions() {
  std::cout << "Welcome to Conway's Game of Life.\n"
    << "This game uses a gird of size " << MAX_ROW << " by " << MAX_COL
    << " in which each\ncell can either be occupied by an organism or not "
    << "according\nto the number of neighboring cells which are alive.\n\n";
}

/*
 * Pre:   None.
 * Post:  The Life object contains a configuration specified by the user
 */
void Life::initialize() {
  for (int row {}; row <= MAX_ROW + 1; ++row) {
    for (int col {}; col <= MAX_COL + 1; ++col) {
      grid[row][col] = 0;
    }
  }

  int row {}, col {};
  std::cout << "List the coordinates for living cells.\n"
    << "Terminate the list with the special pair -1 -1\n";
  std::cin >> row >> col;
  while (row != -1 || col != -1) {
    if (row >= 1 && row <= MAX_ROW) {
      if (col >= 1 && col <= MAX_COL) {
        grid[row][col] = 1;
      } else {
        std::cout << "Column " << col << " is out of range.\n";
      }
    } else {
        std::cout << "Row " << row << " is out of range.\n";
    }
    std::cin >> row >> col;
  }
}

/*
 * Pre:   THe Life object contains a configuration
 * Post:  The configuration is written for the user
 */
void Life::print() {
  std::cout << "The current Life configuration is:\n";
  for (int row {1}; row <= MAX_ROW + 1; ++row) {
    for (int col {1}; col <= MAX_COL + 1; ++col) {
        std::cout << (grid[row][col] == 1 ? '*' : ' ');
    }
    std::cout << '\n';
  }
}

/*
 * Pre:   The Life object contains a configuration
 * Post:  THe Life object contains the next generation of configuration
 */
void Life::update() {
  int new_grid[MAX_ROW + 2][MAX_COL + 2];
  for (int row {1}; row <= MAX_ROW; ++row) {
    for (int col {1}; col <= MAX_COL; ++col) {
      switch (neighbor_count(row, col)) {
          case 2:     // status stays the same
            new_grid[row][col] = grid[row][col];
            break;
          case 3:     // cell is now alive
            new_grid[row][col] = 1;
            break;
          default:     // cell is now dead
            new_grid[row][col] = 0;
            break;
      }
    }
  }

  // copy new grid back as the new configuration
  for (int row {1}; row <= MAX_ROW; ++row) {
    for (int col {1}; col <= MAX_COL; ++col) {
      grid[row][col] = new_grid[row][col];
    }
  }
}

/*
 * Pre:   The Life object contains a configuration, and the coordinates
 *        row and col define a cell inside its hedge.
 * Post:  The number of living neighbos of the specified cell is returned.
 */
int Life::neighbor_count(int row, int col) {
  int count {};
  for (int i {row - 1}; i <= row + 1; ++i) {
    for (int j {col - 1}; j <= col + 1; ++j) {
      // increase the count if the neighbor is alive
      count += grid[i][j];
    }
  }
  // reduce count since cell is not its own neighbor
  count -= grid[row][col];

  return count;
}

void Life::test_neighbor_count() {
  for (int row {1}; row <= MAX_ROW; ++row) {
    for (int col {1}; col <= MAX_COL; ++col) {
      std::cout << neighbor_count(row, col) << ' ';
    }
    std::cout << '\n';
  }
}
