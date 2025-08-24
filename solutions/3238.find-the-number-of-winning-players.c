#include <stdbool.h>
#include <stdlib.h>

// @leet start
int winningPlayerCount(int n, int **pick, int pickSize, int *pickColSize) {
  int **colors = (int **)malloc(n * sizeof(int *));

  for (int i = 0; i < n; i++) {
    colors[i] = calloc(11, sizeof(int));
  }

  for (int i = 0; i < pickSize; i++) {
    colors[pick[i][0]][pick[i][1]] += 1;
  }

  int total = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 10; j++) {
      if (colors[i][j] > i) {
        total += 1;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    free(colors[i]);
  }
  free(colors);

  return total;
}
// @leet end
