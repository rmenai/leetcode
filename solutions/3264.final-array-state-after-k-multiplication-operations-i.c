#include <stdbool.h>
#include <stdlib.h>

// @leet start
int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
  int* modifiedNums = (int*)malloc(numsSize * sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    modifiedNums[i] = nums[i];
  }

  for (int _ = 0; _ < k; _++) {
    int minIndex = 0;
    for (int i = 0; i < numsSize; i++) {
      if (modifiedNums[i] < modifiedNums[minIndex]) {
        minIndex = i;
      }
    }

    modifiedNums[minIndex] *= multiplier;
  }

  *returnSize = numsSize;
  return modifiedNums;
}
// @leet end
