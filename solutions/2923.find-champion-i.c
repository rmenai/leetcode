#include <stdbool.h>

// @leet start
int findChampion(int** grid, int gridSize, int* gridColSize) {
  for (int i = 0; i < gridSize; i++) {
    bool strong = true;

    for (int j = 0; j < gridSize; j++) {
      if (j != i && grid[j][i] == 1) {
        strong = false;
      }
    }

    if (strong) {
      return i;
    }
  }

  return -1;
}
// @leet end
