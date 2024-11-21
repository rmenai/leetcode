#include <stdlib.h>

// @leet start
const int WALL = 2;
const int SEEN = 1;
const int HIDDEN = 0;

int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize) {
  int **board = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    board[i] = (int *)calloc(n, sizeof(int));
  }

  for (int k = 0; k < wallsSize; k++) {
    int *wall = walls[k];
    board[wall[0]][wall[1]] = WALL;
  }

  for (int k = 0; k < guardsSize; k++) {
    int *guard = guards[k];
    board[guard[0]][guard[1]] = WALL;
  }

  for (int k = 0; k < guardsSize; k++) {
    int *guard = guards[k];
    int i = guard[0];
    for (int j = guard[1] - 1; j >= 0; j--) {
      if (board[i][j] == WALL) break;
      if (board[i][j] == HIDDEN) board[i][j] = SEEN;
    }

    for (int j = guard[1] + 1; j < n; j++) {
      if (board[i][j] == WALL) break;
      if (board[i][j] == HIDDEN) board[i][j] = SEEN;
    }

    int j = guard[1];
    for (int i = guard[0] - 1; i >= 0; i--) {
      if (board[i][j] == WALL) break;
      if (board[i][j] == HIDDEN) board[i][j] = SEEN;
    }

    for (int i = guard[0] + 1; i < m; i++) {
      if (board[i][j] == WALL) break;
      if (board[i][j] == HIDDEN) board[i][j] = SEEN;
    }
  }

  int hiddenCount = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == HIDDEN) {
        hiddenCount++;
      }
    }
    free(board[i]);
  }
  free(board);
  
  return hiddenCount;
}
// @leet end
