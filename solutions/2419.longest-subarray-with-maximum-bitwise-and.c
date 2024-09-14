#include <stdlib.h>

// @leet start
int longestSubarray(int* nums, int numsSize) {
  int currLen = 1, maxLen = 1, maxVal = nums[0];
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] > maxVal) {
      currLen = 1, maxLen = 1;
      maxVal = nums[i];
    }

    else if (nums[i] == maxVal && nums[i - 1] == maxVal) {
      if (++currLen > maxLen) {
        maxLen = currLen;
      }
    }

    else {
      currLen = 1;
    }
  }

  return maxLen;
}
// @leet end
