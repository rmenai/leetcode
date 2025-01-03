#include <math.h>

// @leet start
int waysToSplitArray(int* nums, int numsSize) {
  int totalSum = 0;
  for (int i = 0; i < numsSize; i++) {
    totalSum += nums[i];
  }

  int leftSum = 0;
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
