#include <stdlib.h>

// @leet start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** rotateTheBox(char** box, int boxSize, int* boxColSize, int* returnSize, int** returnColumnSizes){
  *returnSize = boxColSize[0];
  *returnColumnSizes = (int *)malloc(boxSize * sizeof(int));

  int **reversedBox = (int **)malloc(boxColSize[0] * sizeof(int *));

  for (int i = 0; i < *returnSize; i++) {
    reversedBox[i] = (int *)malloc(( * sizeof(int));
  }
}
// @leet end
