#include <stdlib.h>

// @leet start
int countServers(int **grid, int gridSize, int *gridColSize) {
  int m = gridSize;
  int n = gridColSize[0];

  int **status = (int **)malloc(m * sizeof(int *));

  for (int i = 0; i < m; i++) {
    status[i] = (int *)calloc(n, sizeof(int));
  }

  for (int i = 0; i < m; i++) {
    int columnsCount = 0;

    for (int j = 0; j < n; j++) {
      columnsCount += grid[i][j];
    }

    if (columnsCount >= 2) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          status[i][j] = 1;
        }
      }
    }
  }

  for (int j = 0; j < n; j++) {
    int rowsCount = 0;

    for (int i = 0; i < m; i++) {
      rowsCount += grid[i][j];
    }

    if (rowsCount >= 2) {
      for (int i = 0; i < m; i++) {
        if (grid[i][j] == 1) {
          status[i][j] = 1;
        }
      }
    }
  }

  int count = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      count += status[i][j];
    }

    free(status[i]);
  }

  free(status);
  return count;
}
// @leet end
