#include <stdlib.h>

// @leet start
#include <stdlib.h>

int maxHeight(int **isWater, int isWaterSize, int *isWaterColSize, int initial_i, int initial_j) {
  if (isWater[initial_i][initial_j]) {
    return 0;
  }

  int height = 0;

  int i = initial_i;
  int j = initial_j;

  int directions[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

  while (1) {
    for (int k = 0; k < 4; k++) {
      int dy = directions[k][0];
      int dx = directions[k][1];

      for (int _ = 0; _ < height; _++) {
        i += dy;
        j += dx;

        if (0 <= i && 0 <= j && i < isWaterSize && j < isWaterColSize[0]) {
          if (isWater[i][j]) {
            return height;
          }
        }
      }
    }

    height++;
    i--;
  }

  return height;
}

int **highestPeak(int **isWater, int isWaterSize, int *isWaterColSize, int *returnSize, int **returnColumnSizes) {
  int **map = (int **)malloc(isWaterSize * sizeof(int *));

  for (int i = 0; i < isWaterSize; i++) {
    map[i] = (int *)malloc(isWaterColSize[i] * sizeof(int));
  }

  for (int i = 0; i < isWaterSize; i++) {
    for (int j = 0; j < isWaterColSize[i]; j++) {
      map[i][j] = maxHeight(isWater, isWaterSize, isWaterColSize, i, j);
    }
  }

  *returnSize = isWaterSize;
  *returnColumnSizes = isWaterColSize;
  return map;
}

// @leet end
