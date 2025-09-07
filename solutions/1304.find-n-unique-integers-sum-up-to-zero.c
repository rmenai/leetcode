#include <stdbool.h>
#include <stdlib.h>

// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize) {
  int* nums = (int*)malloc(n * sizeof(int));

  for (int i = 0; i < n / 2; i++) {
    nums[i] = i + 1;
    nums[n - i - 1] = -nums[i];
  }

  if (n % 2 == 1) {
    nums[n / 2] = 0;
  }

  *returnSize = n;
  return nums;
}
// @leet end
