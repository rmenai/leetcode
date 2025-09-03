#include <stdbool.h>
#include <stdlib.h>

// @leet start
int cmp(const void *a_p, const void *b_p) {
  int *a = *(int **)a_p;
  int *b = *(int **)b_p;

  if (a[0] != b[0]) {
    return a[0] - b[0];
  }

  return b[1] - a[1];
}

int numberOfPairs(int **points, int pointsSize, int *pointsColSize) {
  int **sortedPoints = (int **)malloc(pointsSize * sizeof(int *));
  for (int i = 0; i < pointsSize; i++) {
    sortedPoints[i] = points[i];
  }

  qsort(sortedPoints, pointsSize, sizeof(int *), cmp);

  int count = 0;

  for (int i = 0; i < pointsSize - 1; i++) {
    int *a = sortedPoints[i];
    int maxY = -2000000000;

    for (int j = i + 1; j < pointsSize; j++) {
      int *b = sortedPoints[j];

      if (a[1] >= b[1]) {
        if (b[1] > maxY) {
          maxY = b[1];
          count++;
        }
      }
    }
  }

  free(sortedPoints);
  return count;
}
// @leet end
