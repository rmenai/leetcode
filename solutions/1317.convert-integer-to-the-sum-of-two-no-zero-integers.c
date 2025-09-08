#include <stdbool.h>
#include <stdlib.h>

// @leet start
bool hasZero(int n) {
  if (n == 0) {
    return true;
  }

  while (n > 0) {
    if (n % 10 == 0) {
      return true;
    }

    n /= 10;
  }

  return false;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getNoZeroIntegers(int n, int* returnSize) {
  int* result = (int*)malloc(2 * sizeof(int));
  result[0] = -1;
  result[1] = -1;

  for (int i = 1; i <= n / 2; i++) {
    if (!hasZero(i) && !hasZero(n - i)) {
      result[0] = i;
      result[1] = n - i;
      break;
    }
  }

  *returnSize = 2;
  return result;
}
// @leet end
