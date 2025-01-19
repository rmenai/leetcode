#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

// @leet start
int min(int a, int b) {
  if (a <= b) {
    return a;
  }

  return b;
}

// On each call, we assume that we have the maximum water level of (i, j)
void putWater(int **heightMap, int **waterLevel, int i, int j) {
  int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  for (int k = 0; k < 4; k++) {
    int ni = i + directions[k][0];
    int nj = j + directions[k][1];

    if (waterLevel[ni][nj] > waterLevel[i][j]) {
      if (heightMap[ni][nj] >= heightMap[i][j]) {
        waterLevel[ni][nj] = waterLevel[i][j];
        putWater(heightMap, waterLevel, ni, nj);
        continue;
      }

      if (waterLevel[ni][nj] > heightMap[i][j]) {
        waterLevel[ni][nj] = heightMap[i][j];
        putWater(heightMap, waterLevel, ni, nj);
      }
    }
  }
}

int trapRainWater(int **heightMap, int heightMapSize, int *heightMapColSize) {
  int rows = heightMapSize + 2;
  int columns = heightMapColSize[0] + 2;

  int **waterLevel = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    waterLevel[i] = (int *)malloc(columns * sizeof(int));
    for (int j = 0; j < columns; j++) {
      waterLevel[i][j] = INT_MAX;
    }
  }

  for (int i = 1; i < rows - 1; i++) {
    waterLevel[i][1] = INT_MIN;
    waterLevel[i][columns - 1] = INT_MIN;

    putWater(heightMap, waterLevel, i, 1);
    putWater(heightMap, waterLevel, i, columns - 1);
  }
  for (int j = 1; j < columns - 1; j++) {
    waterLevel[1][j] = INT_MIN;
    waterLevel[rows - 1][j] = INT_MIN;

    putWater(heightMap, waterLevel, 1, j);
    putWater(heightMap, waterLevel, rows - 1, j);
  }

  int waterVolume = 0;
  for (int i = 1; i < rows - 1; i++) {
    for (int j = 1; j < columns - 1; j++) {
      waterVolume += min(0, heightMap[i][j] - waterLevel[i][j]);
    }

    free(waterLevel[i]);
  }

  free(waterLevel);

  return waterVolume;
}
// @leet end
