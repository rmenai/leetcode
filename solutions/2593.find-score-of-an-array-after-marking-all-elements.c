#include <stdlib.h>

// @leet start
int compar(const void *a, const void *b) {
  int *first = *(int **)a;
  int *second = *(int **)b;

  int diff = first[1] - second[1];

  if (diff == 0) {
    return first[0] - second[0];
  }

  return diff;
}

// void mark(int **arr, int size, int num) {
//   int low = 0;
//   int high = size - 1;
//
//   while (low < high) {
//     int mid = high - (high - low) / 2;
//
//     if (num < arr[mid][1]) {
//       high = mid - 1;
//     } else if (num > arr[mid][1]) {
//       low = mid + 1;
//     } else {
//       low = mid;
//       high = mid;
//     }
//   }
//
//   arr[low][2] = 1;
// }

long long findScore(int* nums, int numsSize) {
  int **sortedNums = (int **)malloc(numsSize * sizeof(int *));
  
  for (int i = 0; i < numsSize; i++) {
    sortedNums[i] = (int *)malloc(3 * sizeof(int));

    sortedNums[i][0] = i;
    sortedNums[i][1] = nums[i];
    sortedNums[i][2] = 0;
  }

  qsort(sortedNums, numsSize, sizeof(int *), compar);

  long long score = 0;
  for (int i = 0; i < numsSize; i++) {
    if (sortedNums[i][2] == 0) {
      score += sortedNums[i][1];

      int before = sortedNums[i][0] - 1;
      int after = sortedNums[i][0] + 1;

      if (before >= 0) mark(sortedNums, numsSize, nums[before]);
      if (after < numsSize) mark(sortedNums, numsSize, nums[after]);
    }
  }

  free(sortedNums);
  return score;
}
// @leet end
