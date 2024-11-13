#include <stdlib.h>
#include <stdbool.h>

// @leet start
int compare(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

long long countFairPairs(int *nums, int numsSize, int lower, int upper) {
  qsort(nums, numsSize, sizeof(int), compare);
  
  int count = 0;
  for (int i = 0; i < numsSize - 1; i++) {
    int left = i + 1;
    int right = numsSize;
    int mid;
    while (left <= right) {
      int mid = (left + right) / 2;
      int sum = nums[i] + nums[mid];
      if (sum > upper) {
        right = mid - 1;
        continue;
      }

      if (sum < lower) {
        left = mid + 1;
        continue;
      }

      for (int i)

    }
  }

  return count;
}
// @leet end
