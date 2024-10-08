#include <stdlib.h>

// @leet start
int* lexicalOrder(int n, int* returnSize) {
  int* result = malloc(n * sizeof(int));

  result[0] = 1;
  for (int k = 1; k < n; k++) {
    if (result[k - 1] * 10 <= n) {
      result[k] = result[k - 1] * 10;
      continue;
    }
    
    if (result[k - 1] + 1 <= n && result[k - 1] % 10 < 9) {
      result[k] = result[k - 1] + 1;
      continue;
    }

    result[k] = result[k - 1];
    while (result[k] % 10 == 9 || result[k] + 1 > n) {
      result[k] /= 10;
    }

    result[k]++;
  }

  *returnSize = n;
  return result;
}
// @leet end
