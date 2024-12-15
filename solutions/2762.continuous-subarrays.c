#include <limits.h>
#include <stdlib.h>

// @leet start
long long continuousSubarrays(int* nums, int numsSize) {
  long long count = 0;
  int j = 0;

  int min = INT_MAX;
  int max = INT_MIN;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > max) max = nums[i];
    if (nums[i] < min) min = nums[i];

    if (max - min > 2) {
      int n = i - j;
      count += n * (n + 1) / 2;

      j = i;
      max = nums[i];
      min = nums[i];

      while (j > 0 && abs(nums[i] - nums[j - 1]) <= 2) {
        j--;
        if (nums[j] > max) max = nums[j];
        if (nums[j] < min) min = nums[j];
      }

      if (j < i) {
        n = i - j;
        count -= n * (n + 1) / 2;
      }
    }
  }

  int n = numsSize - j;
  count += n * (n + 1) / 2;
  return count;
}
// @leet end
