#include <limits.h>
#include <stdlib.h>

// @leet start
long long gridGame(int **grid, int gridSize, int *gridColSize) {
  int columns = gridColSize[0];
  long long **prefixSum = (long long **)malloc(2 * sizeof(long long *));

  for (int i = 0; i < 2; i++) {
    prefixSum[i] = (long long *)calloc(columns, sizeof(long long));
  }

  prefixSum[0][0] = grid[0][0];
  prefixSum[1][0] = grid[1][0];

  for (int j = 1; j < columns; j++) {
    prefixSum[0][j] = prefixSum[0][j - 1] + grid[0][j];
    prefixSum[1][j] = prefixSum[1][j - 1] + grid[1][j];
  }

  long long min = LONG_MAX;

  for (int i = 0; i < columns; i++) {
    long long sum1 = prefixSum[0][columns - 1] - prefixSum[0][i];
    long long sum2 = i > 0 ? prefixSum[1][i - 1] : 0;

    long long max = sum1 > sum2 ? sum1 : sum2;
    min = max < min ? max : min;
  }

  return min;
}
// @leet end
