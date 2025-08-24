#include <stdbool.h>
#include <stdlib.h>

// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
  int* result = (int*)malloc(2 * numsSize * sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    result[i] = nums[i];
    result[i + numsSize] = nums[i];
  }

  *returnSize = 2 * numsSize;
  return result;
}
// @leet end
