#include <stdbool.h>

// @leet start
int divisorsCount(int num) {
  int count = 1;
  for (int n = 2; n <= num; n++) {
    if (num % n == 0) {
      count++;
    }
  }

  return count;
}

int closestMaximumPrime(int num) {
  for (int n = num - 1; n >= 2; n--) {
    if (divisorsCount(n) == 2) {
      return n;
    }
  }

  return 0;
}

bool primeSubOperation(int* nums, int numsSize) {
  int lowerBound = 0;
  for (int i = 1; i < numsSize; i++) {
    lowerBound = nums[i - 1] - closestMaximumPrime(nums[i - 1] - lowerBound);

    if (lowerBound >= nums[i]) {
      return false;
    }
  }

  return true;
}
// @leet end
