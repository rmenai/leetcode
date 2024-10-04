#include <stdlib.h>

// @leet start
int compare(const void* a, const void* b) {
  return *(int *)b - *(int *)a;
}

long long dividePlayers(int* skill, int skillSize) {
  int sum = 0;
  for (int i = 0; i < skillSize; i++) {
    sum += skill[i];
  }

  // Make sure a solution exists
  if (sum * 2 % skillSize != 0) {
    return -1;
  }

  // Calculate group average
  int average = sum * 2 / skillSize;
  qsort(skill, skillSize, sizeof(int), compare);

  long long chemistry = 0;
  for (int i = 0; i < (skillSize / 2); i++) {
    // Make sure the items are correct
    if (skill[skillSize - i - 1] != average - skill[i]) {
      return -1;
    }

    chemistry += skill[skillSize - i - 1] * skill[i];
  }

  return chemistry;
}
// @leet end
