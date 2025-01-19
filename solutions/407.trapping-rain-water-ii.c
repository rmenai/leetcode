#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

// @leet start
#define WATER 2
#define WALL 1
#define EMPTY 3

void drain(int ***map, int rows, int columns, int height, int y, int x) {
  if (map[height][y][x] != WATER) {
    return;
  }

  bool isEmpty = false;

  if (map[height - 1][y][x] == EMPTY) {
    isEmpty = true;
  }

  int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  for (int k = 0; k < 4; k++) {
    int dy = directions[k][0];
    int dx = directions[k][1];

    int ny = y + dy;
    int nx = x + dx;

    if (!(ny >= 0 && nx >= 0 && ny < rows && nx < columns)) {
      isEmpty = true;
      continue;
    }

    if (map[height][ny][nx] == EMPTY) {
      isEmpty = true;
      continue;
    }
  }

  if (isEmpty) {
    map[height][y][x] = EMPTY;

    for (int k = 0; k < 4; k++) {
      int dy = directions[k][0];
      int dx = directions[k][1];

      int ny = y + dy;
      int nx = x + dx;

      if (!(ny >= 0 && nx >= 0 && ny < rows && nx < columns)) {
        continue;
      }

      if (map[height][ny][nx] == WATER) {
        drain(map, rows, columns, height, ny, nx);
      }
    }
  }
}

int ***initilizeMap(int maxHeight, int heightMapSize, int *heightMapColSize) {
  int ***map = (int ***)malloc((maxHeight + 1) * sizeof(int **));

  // Initilalize simulation
  for (int height = 0; height <= maxHeight; height++) {
    map[height] = (int **)malloc(heightMapSize * sizeof(int *));
    for (int i = 0; i < heightMapSize; i++) {
      map[height][i] = (int *)malloc(heightMapColSize[i] * sizeof(int));
      for (int j = 0; j < heightMapColSize[i]; j++) {
        map[height][i][j] = WATER;
      }
    }
  }

  return map;
}

int trapRainWater(int **heightMap, int heightMapSize, int *heightMapColSize) {
  int maxHeight = 0;
  for (int i = 0; i < heightMapSize; i++) {
    for (int j = 0; j < heightMapColSize[i]; j++) {
      if (heightMap[i][j] > maxHeight) {
        maxHeight = heightMap[i][j];
      }
    }
  }

  // Fill simulation
  int ***simulation = initilizeMap(maxHeight, heightMapSize, heightMapColSize);

  for (int i = 0; i < heightMapSize; i++) {
    for (int j = 0; j < heightMapColSize[i]; j++) {
      simulation[0][i][j] = WALL;
    }
  }

  for (int height = 1; height <= maxHeight; height++) {
    for (int i = 0; i < heightMapSize; i++) {
      for (int j = 0; j < heightMapColSize[i]; j++) {
        if (height <= heightMap[i][j]) {
          simulation[height][i][j] = WALL;
        }
      }
    }
  }

  // Drain water
  for (int height = 1; height <= maxHeight; height++) {
    for (int i = 0; i < heightMapSize; i++) {
      for (int j = 0; j < heightMapColSize[i]; j++) {
        drain(simulation, heightMapSize, heightMapColSize[i], height, i, j);
      }
    }
  }

  // Calculate water volume
  int waterVolume = 0;
  for (int height = 1; height <= maxHeight; height++) {
    for (int i = 0; i < heightMapSize; i++) {
      for (int j = 0; j < heightMapColSize[i]; j++) {
        if (simulation[height][i][j] == WATER) {
          waterVolume++;
        }
      }
    }
  }

  // Free array
  for (int height = 0; height <= maxHeight; height++) {
    for (int i = 0; i < heightMapSize; i++) {
      free(simulation[height][i]);
    }

    free(simulation[height]);
  }

  free(simulation);

  return waterVolume;
}
// @leet end
