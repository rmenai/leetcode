#include <math.h>
#include <stdint.h>

// @leet start
int waysToSplitArray(int* nums, int numsSize) {
  long long totalSum = 0;
  for (int i = 0; i < numsSize; i++) {
    totalSum += nums[i];
  }

  long long leftSum = 0;
  int count = 0;
  for (int i = 0; i < numsSize - 1; i++) {
    leftSum += nums[i];
    if (leftSum >= ceil(totalSum / 2.0)) {
      count++;
    }
  }

  return count;
}
// @leet end
