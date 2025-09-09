#include <stdbool.h>

// @leet start
int min(int a, int b) { return a < b ? a : b; }

int peopleAwareOfSecret(int n, int delay, int forget) {
  long long MOD = 1000000007;

  long long dp[n + 1];
  for (int i = 0; i <= n; ++i) {
    dp[i] = 0;
  }

  dp[1] = 1;

  long long count = 0;
  for (int i = 2; i <= n; i++) {
    if (i - delay > 0) {
      count = (count + dp[i - delay]) % MOD;
    }

    if (i - forget > 0) {
      count = (count - dp[i - forget] + MOD) % MOD;
    }

    dp[i] = count;
  }

  count = 0;
  for (int i = n - forget + 1; i <= n; i++) {
    if (i > 0) {
      count = (count + dp[i]) % MOD;
    }
  }

  return (int)count;
}
// @leet end
