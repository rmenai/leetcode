#include <stdlib.h>

// @leet start
int powerOfSubarray(int *nums, int numsSize, int start, int end) {
  for (int i = start + 1; i < end; i++) {
    if (nums[i - 1] + 1 != nums[i]) {
      return -1;
    }
  }

  return nums[end - 1];
}

int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
  int size = numsSize - k + 1;
  int *result = (int *)malloc(size * sizeof(int));

  for (int i = 0; i <= numsSize - k; i++) {
    result[i] = powerOfSubarray(nums, numsSize, i, i + k);
  }

  *returnSize = size;
  return result;
}
// @leet end
