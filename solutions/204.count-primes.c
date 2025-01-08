#include <stdlib.h>

// @leet start
int countPrimes(int n) {
  int *primes = (int *)calloc(n + 1, sizeof(int));

  for (int i = 2; i <= n; i++) {
    if (primes[i] == 0) {
      for (int j = 2 * i; j <= n; j += i) {
        primes[j] = 1;
      }
    }
  }

  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (primes[i] == 0) {
      count++;
    }
  }

  free(primes);
  return count;
}
// @leet end
