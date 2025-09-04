#include <stdbool.h>
#include <stdlib.h>

// @leet start
int abs(int x) {
  if (x < 0) {
    return -x;
  }

  return x;
}

int findClosest(int x, int y, int z) {
  int a = abs(x - z);
  int b = abs(y - z);

  if (a > b) {
    return 2;
  }

  if (a < b) {
    return 1;
  }

  return 0;
}
// @leet end
