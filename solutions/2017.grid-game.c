#include <stdlib.h>

// @leet start
void calculatePrefix(int **grid, int **prefixSum, int columns) {
  prefixSum[0][0] = grid[0][0];
  prefixSum[1][0] = grid[1][0];

  for (int j = 1; j < columns; j++) {
    prefixSum[0][j] = prefixSum[0][j - 1] + grid[0][j];
    prefixSum[1][j] = prefixSum[1][j - 1] + grid[1][j];
  }
}

long long play(int **grid, int **prefixSum, int columns) {
  long long points = 0;

  points += grid[0][0];
  grid[0][0] = 0;

  int i = 0;
  int j = 0;

  while (!(i == 1 && j == columns - 1)) {
    if (j == columns - 1) {
      i++;
    } else if (i == 0) {
      long long sum1 = prefixSum[0][columns - 1] - prefixSum[0][j];

      long long sum2;
      if (j == 0) {
        sum2 = prefixSum[1][columns - 1];
      } else {
        sum2 = prefixSum[1][columns - 1] - prefixSum[1][j - 1];
      }

      if (sum1 > sum2) {
        j++;
      } else {
        i++;
      }
    } else {
      j++;
    }

    points += grid[i][j];
    grid[i][j] = 0;
  }

  return points;
}

long long gridGame(int **grid, int gridSize, int *gridColSize) {
  int columns = gridColSize[0];
  int **prefixSum = (int **)malloc(2 * sizeof(int *));

  for (int i = 0; i < 2; i++) {
    prefixSum[i] = (int *)calloc(columns, sizeof(int));
  }

  calculatePrefix(grid, prefixSum, columns);  // Robot 1
  play(grid, prefixSum, columns);

  calculatePrefix(grid, prefixSum, columns);  // Robot 2
  return play(grid, prefixSum, columns);
}
// @leet end
