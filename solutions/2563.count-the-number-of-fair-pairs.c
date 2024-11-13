#include <stdlib.h>
#include <stdbool.h>

// @leet start
int compare(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

long long countFairPairs(int *nums, int numsSize, int lower, int upper) {
  qsort(nums, numsSize, sizeof(int), compare);
  
  long long count = 0;
  for (int i = 0; i < numsSize - 1; i++) {
    int left = i + 1;
    int right = numsSize - 1;

    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[i] + nums[mid] >= lower) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    int lowIndex = left;
    
    left = i + 1;
    right = numsSize - 1;

    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[i] + nums[mid] <= upper) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    int highIndex = right;

    if (lowIndex <= highIndex) {
      count += (highIndex - lowIndex + 1);
    }
  }

  return count;
}
// @leet end
