#include <stdbool.h>

// @leet start
int countBits(long a) {
  int count = 0;

  while (a > 0) {
    count += a % 2;
    a >>= 1;
  }

  return count;
}

int makeTheIntegerZero(int num1, int num2) {
  for (int c = 0; c < 37; c++) {
    long num = (long)num1 - c * (long)num2;

    // Wow!
    // https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/solutions/7157889/completed-proof-it-took-me-2-hours-k-is-ei0ur/
    if (countBits(num) <= c && c <= num) {
      return c;
    }
  }

  return -1;
}
// @leet end
