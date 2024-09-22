#include <stdlib.h>

// @leet start
int findKthNumber(int n, int k) {
  long* result = malloc(n * sizeof(long));

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

  return result[k - 1];
}
// @leet end
