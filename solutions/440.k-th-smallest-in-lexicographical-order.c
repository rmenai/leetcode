#include <math.h>
#include <stdlib.h>

// @leet start
// int getLength(int num) {
//   int digits = 1;
//   while (num / 10 > 0) {
//     digits++;
//     num /= 10;
//   }
//
//   return digits;
// }
//
// int getChildrenTotalSize(int digits) {
//   int total = 0;
//   for (int i = 0; i < digits - 1; i++) {
//     total += 9 * pow(10, i);
//   }
//
//   return total;
// }
//
// int findKthNumber(int n, int k) {
//   int digits = getLength(n);
//   int childSize = getChildrenTotalSize(digits);
//
//   int remainder = n - childSize;
//
//   // Find first digit
//   int nextK = k;
//   int firstDigit = 0;
//   while (nextK > 0) {
//     nextK -= childSize / 9;
//     if (remainder > pow(10, digits)) {
//       nextK -= pow(10, digits);
//       remainder -= 100;
//     }
//
//     else {
//       nextK -= remainder;
//       remainder = 0;
//     }
//
//     firstDigit++;
//   }
//
//   // Make next K relative
//   int depth = digits - 1;
//   nextK += childSize / 9 - 1;
//   if (remainder > pow(10, digits)) {
//     nextK += 100;
//     depth = digits;
//   }
//
//   int result = k;
//
//   // Find rest of digits (tree is now full)
//   k = nextK;
//   int increment = childSize / 9;
//   if (depth == digits - 1) {
//     increment = (increment - 1) / 10;
//   }
//
//   while (increment > 0) {
//     int nextDigit = k / increment;
//
//     result = result * 10 + nextDigit;
//     // remainder = k % increment;
//     k %= increment - 2;
//     increment = increment - 1 / 10;
//   }
//
//   return result;
// }
long countSteps(long prefix, long n) {
  long current = prefix;
  long next = prefix + 1;
  long steps = 0;

  // While current prefix is valid
  while (current <= n) {
    steps += fmin(n + 1, next) - current;
    current *= 10;
    next *= 10;
  }

  return steps;
}

int findKthNumber(int n, int k) {
  int current = 1;
  k--;  // Since we consider the 1st smallest as 'current'

  while (k > 0) {
    long steps = countSteps(current, n);
    if (steps <= k) {
      // Move to the next sibling
      current++;
      k -= steps;
    } else {
      // Move to the next child
      current *= 10;
      k--;
    }
  }

  return current;
}
// @leet end
