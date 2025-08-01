#include <stdlib.h>

// @leet start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
  int** result = (int**)malloc(numRows * sizeof(int*));
  int* sizes = (int*)malloc(numRows * sizeof(int));

  result[0] = (int*)malloc(sizeof(int));
  result[0][0] = 1;
  sizes[0] = 1;

  for (int i = 1; i < numRows; i++) {
    result[i] = (int*)malloc((i + 1) * sizeof(int));
    sizes[i] = i + 1;

    result[i][0] = 1;
    result[i][i] = 1;

    for (int j = 1; j < i; j++) {
      result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
    }
  }

  *returnSize = numRows;
  *returnColumnSizes = sizes;
  return result;
}
// @leet end
