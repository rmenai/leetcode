#include <stdbool.h>
#include <stdlib.h>

// @leet start
int numbersOfSetBits(int num) {
  int sumOfAllBits = 0;

  for (int _ = 0; _ < 32; _++) {
    sumOfAllBits += num & 1;
    num >>= 1;
  }

  return sumOfAllBits;
}

bool canSortArray(int *nums, int numsSize) {
  int *sortedNums = malloc(sizeof(int) * numsSize);

  sortedNums[0] = nums[0];
  for (int i = 1; i < numsSize; i++) {
    sortedNums[i] = nums[i];
    for (int j = i - 1; j >= 0; j--) {
      if (sortedNums[j] > sortedNums[j + 1]) {
        if (numbersOfSetBits(sortedNums[j]) != numbersOfSetBits(sortedNums[j + 1])) {
          free(sortedNums);
          return false;
        }

        int temp = sortedNums[j];
        sortedNums[j] = sortedNums[j + 1];
        sortedNums[j + 1] = temp;

      } else {
        break;
      }
    }
  }

  free(sortedNums);
  return true;
}
// @leet end
