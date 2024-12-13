#include <stdlib.h>
#include <stdbool.h>

// @leet start

typedef struct Num {
  int value;
  int index;
  struct Num next;
  struct Num previous;

} number;

int compar(const void *a, const void *b) {
  number *first = *(number **)a;
  number *second = *(number **)b;

  int diff = first->value - second->value;

  if (diff == 0) {
    return first->index - second->index;
  }

  return diff;
}

long long findScore(int* nums, int numsSize) {
  number **sortedNums = (number **)malloc(numsSize * sizeof(number *));
  
  for (int i = 0; i < numsSize; i++) {
    sortedNums[i] = (number *)malloc(sizeof(number *);

    sortedNums[i]->value = nums[i];
    sortedNums[i]->index = i; 
    sortedNums[i]->previous = i > 0 ? sortedNums[i - 1] : NULL; 
    sortedNums[i]->next = i < numsSize - 1 ? sortedNums[i + 1] : NULL;
  }

  qsort(sortedNums, numsSize, sizeof(number **), compar);

  long long score = 0;
  for (int i = 0; i < numsSize; i++) {
    number *num = sortedNums[i];
    if (num.) {
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
