#include <stdlib.h>
#include <stdbool.h>

// @leet start
int findLengthOfShortestSubarray(int* arr, int arrSize) {
  bool isSorted = false;

  int i = 1;
  int j = 0;

  while (!isSorted) {
    if (arr[i] > arr[i - 1]) {
      i++;
      continue;
    }

  }
}
// @leet end
