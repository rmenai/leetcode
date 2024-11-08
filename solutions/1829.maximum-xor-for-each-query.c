#include <stdlib.h>

// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
  int *answer = malloc(sizeof(int) * numsSize);
  *returnSize = numsSize;

  int initialXOR = nums[1];
  for (int i = 1; i < numsSize; i++) {
    initialXOR ^= nums[i];
  }


  return answer;
}
// @leet end
