#include <stdbool.h>

// @leet start
int numberOfPairs(int **points, int pointsSize, int *pointsColSize) {
  int count = 0;

  for (int i = 0; i < pointsSize; i++) {
    for (int j = 0; j < pointsSize; j++) {
      if (i == j) {
        continue;
      }

      int *a = points[i];
      int *b = points[j];

      if (a[0] <= b[0] && a[1] >= b[1]) {
        bool empty = true;

        for (int k = 0; k < pointsSize; k++) {
          int *c = points[k];

          if (k == i || k == j) {
            continue;
          }

          if (a[0] <= c[0] && c[0] <= b[0] && a[1] >= c[1] && c[1] >= b[1]) {
            empty = false;
          }
        }

        if (empty) {
          count++;
        }
      }
    }
  }

  return count;
}
// @leet end
