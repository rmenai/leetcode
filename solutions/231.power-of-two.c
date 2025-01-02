#include <math.h>
#include <stdbool.h>

// @leet start
bool isPowerOfTwo(int n) { return n != 0 ? pow(2, floor(log2(n))) == (double)n : false; }
// @leet end
