#include <stdlib.h>

// @leet start
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
  int initialXOR = nums[0];
  for (int i = 1; i < numsSize; i++) {
    initialXOR ^= nums[i];
  }

  int *answer = malloc(sizeof(int) * numsSize);
  int mask = (1 << maximumBit) - 1;
  for (int i = 0; i < numsSize; i++) {
    answer[i] = ~(initialXOR) & mask;
    initialXOR ^= nums[numsSize - i - 1];
  }

  *returnSize = numsSize;
  return answer;
}
// @leet end
