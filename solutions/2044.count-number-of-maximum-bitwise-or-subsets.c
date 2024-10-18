#include <stdlib.h>

// @leet start
int countSubsets(int *nums, int numsSize, int i, int currentOr, int targetOr) {
  if (i  == numsSize) {
    return currentOr == targetOr ? 1 : 0;
  }

  int countWithout = countSubsets(nums, numsSize, i + 1, currentOr, targetOr);
  int countWith = countSubsets(nums, numsSize, i + 1, currentOr | nums[i], targetOr);

  return countWith + countWithout;
}

int countMaxOrSubsets(int* nums, int numsSize) {
  int maxBitwise = 0;
  for (int i = 0; i < numsSize; i++) {
    maxBitwise |= nums[i];
  }

  return countSubsets(nums, numsSize, 0, 0, maxBitwise);
}
// @leet end
