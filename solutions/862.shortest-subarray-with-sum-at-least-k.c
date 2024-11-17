#include <stdlib.h>
#include <stdbool.h>

// @leet start
typedef struct{
} Element;


int shortestSubarray(int* nums, int numsSize, int k) {
  int *prefixArray = (int *)malloc(numsSize * sizeof(int));
  int currentSum = 0;
  for (int i = 0; i < numsSize; i++) {
    currentSum += nums[i];
    prefixArray[i] = currentSum;
  }

  int j = 0;
  int shortestLength = 0;
  for (int i = 0; i < numsSize; i++) {
    // If j < i where we add to current Sum, we go to it
    // Else we just go forward

    if (prefixArray[i] - prefixArray[j - 1] >= k) {
      int length = i - j + 1;
      if (length < shortestLength) {
        shortestLength = length;
      }
    }
  }

  free(prefixArray);
  return shortestLength;
}
// @leet end
