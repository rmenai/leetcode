#include <stdlib.h>

// @leet start
long long maximumSubarraySum(int *nums, int numsSize, int k) {
  int *frequencyTable = (int *)calloc(100001, sizeof(int));

  long long maxSum = 0;
  long long currentSum = 0;

  int left = 0;
  for (int right = 0; right < numsSize; right++) {
    frequencyTable[nums[right]]++;
    currentSum += nums[right];

    while (frequencyTable[nums[right]] > 1) {
      frequencyTable[nums[left]]--;
      currentSum -= nums[left];
      left++;
    }

    if (right - left + 1 == k) {
      if (currentSum > maxSum) {
        maxSum = currentSum;
      }

      frequencyTable[nums[left]]--;
      currentSum -= nums[left];
      left++;
    }
  }

  free(frequencyTable);
  return maxSum;
}
// @leet end
