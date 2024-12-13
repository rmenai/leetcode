#include <stdlib.h>
#include <stdbool.h>

// @leet start

typedef struct Num {
  int value;
  int index;
  struct Num *next;
  struct Num *previous;
  bool marked;
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
    sortedNums[i] = (number *)malloc(sizeof(number));

    sortedNums[i]->value = nums[i];
    sortedNums[i]->index = i; 
    sortedNums[i]->marked = false;
  }

  for (int i = 0; i < numsSize; i++){
    sortedNums[i]->previous = i > 0 ? sortedNums[i - 1] : NULL; 
    sortedNums[i]->next = i < numsSize - 1 ? sortedNums[i + 1] : NULL;
  }

  qsort(sortedNums, numsSize, sizeof(number **), compar);

  long long score = 0;
  for (int i = 0; i < numsSize; i++) {
    number *num = sortedNums[i];
    if (!num->marked) {
      score += num->value;

      if (num->previous != NULL) {
        num->previous->marked = true;
      }

      if (num->next != NULL) {
        num->next->marked = true;
      }
    }
  }

  for (int i = 0; i < numsSize; i++) {
    free(sortedNums[i]);
  }

  free(sortedNums);
  return score;
}
// @leet end
