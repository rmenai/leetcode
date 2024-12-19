#include <stdlib.h>

// @leet start
void fill(int* range, int i, int j) {
  int x = 2 * i;
  int y = 2 * j;

  for (int k = x; k <= y; k++) {
    range[k] = 1;
  }
}

int maxChunksToSorted(int* arr, int arrSize) {
  int length = 2 * arrSize - 1;
  int* range = (int*)malloc(length * sizeof(int));

  for (int i = 0; i < arrSize; i++) {
    fill(range, i, arr[i]);
  }

  int consecutive = 0;
  int count = 0;
  for (int k = 0; k < length; k++) {
    if (range[k] != 1) {
      if (count > 0) {
        consecutive++;
        count = 0;
      }
    } else {
      count++;
    }
  }

  if (count > 0) {
    consecutive++;
  }

  free(range);
  return consecutive;
}
// @leet end
