#include <stdlib.h>

// @leet start
int maximumBeauty(int* nums, int numsSize, int k) {
  int max = nums[0];
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] > max) {
      max = nums[i];
    }
  }

  int *frequency = (int *)calloc(max + 1, sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    frequency[nums[i] - k > 0 ? nums[i] - k : 0]++;
    if (nums[i] + k + 1 <= max) {
      frequency[nums[i] + k + 1]--;
    }
  }

  int maxBeauty = 0;
  int currentSum = 0;

  for (int i = 0; i < max + 1; i++) {
    currentSum += frequency[i];
    if (currentSum > maxBeauty) {
      maxBeauty = currentSum;
    }
  }

  free(frequency);
  return maxBeauty;
}
// @leet end
