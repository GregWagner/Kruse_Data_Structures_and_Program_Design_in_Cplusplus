#ifndef LIFE_HPP
#define LIFE_HPP

int const MAX_ROW {20};
int const MAX_COL {20};

class Life {
  public:
    void instructions();
    void initialize();
    void print();
    void update();

    void test_neighbor_count();

  private:
    int grid[MAX_ROW + 2][MAX_COL + 2]; // allow for 2 extra rows and
                                        // columns for hedge
    int neighbor_count(int row, int col);
};

#endif
