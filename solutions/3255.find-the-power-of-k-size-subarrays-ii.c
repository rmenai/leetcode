#include <stdlib.h>

// @leet start
int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
  if (k == 1) {
    *returnSize = numsSize;
    return nums;
  }

  int size = numsSize - k + 1;
  int *result = (int *)malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    result[i] = -1;
  }

  int counter = 1;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i - 1] + 1 == nums[i]) {
      counter++;
    } else {
      counter = 1;
    }

    if (counter >= k) {
      result[i - k + 1] = nums[i];
    }
  }

  *returnSize = size;
  return result;
}
// @leet end
