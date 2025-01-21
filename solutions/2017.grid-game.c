#include <limits.h>
#include <stdlib.h>

// @leet start
long long gridGame(int **grid, int gridSize, int *gridColSize) {
  int columns = gridColSize[0];
  int **prefixSum = (int **)malloc(2 * sizeof(int *));

  for (int i = 0; i < 2; i++) {
    prefixSum[i] = (int *)calloc(columns, sizeof(int));
  }

  prefixSum[0][0] = grid[0][0];
  prefixSum[1][0] = grid[1][0];

  for (int j = 1; j < columns; j++) {
    prefixSum[0][j] = prefixSum[0][j - 1] + grid[0][j];
    prefixSum[1][j] = prefixSum[1][j - 1] + grid[1][j];
  }

  int min = INT_MAX;

  for (int i = 0; i < columns; i++) {
    int sum1 = prefixSum[0][columns - 1] - prefixSum[0][i];
    int sum2 = i > 0 ? prefixSum[1][i - 1] : 0;

    int max = sum1 > sum2 ? sum1 : sum2;
    min = max < min ? max : min;
  }

  return min;
}
// @leet end
