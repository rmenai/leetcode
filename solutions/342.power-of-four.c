#include <stdbool.h>

// @leet start
bool isPowerOfFour(int n) {
  int mask = 0b01010101010101010101010101010101;
  return n > 0 && (n & (n - 1)) == 0 && (n & mask) == n;
}
// @leet end
