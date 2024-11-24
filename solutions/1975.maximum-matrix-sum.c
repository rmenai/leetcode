#include <stdlib.h>

// @leet start
long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
  long long totalSum = 0;
  int min = 1000001;
  int negativeCount = 0;

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixColSize[i]; j++) {
      totalSum += abs(matrix[i][j]);

      if (matrix[i][j] < 0) {
        negativeCount++;
      }

      if (abs(matrix[i][j]) < min) {
        min = abs(matrix[i][j]);
      }
    }
  }

  if (negativeCount % 2 == 1) {
    totalSum -= 2 * min;
  }

  return totalSum;
}
// @leet end
