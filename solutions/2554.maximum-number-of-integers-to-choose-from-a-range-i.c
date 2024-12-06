#include <stdlib.h>

// @leet start
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
void sortIntegers(int *arr, size_t size) { qsort(arr, size, sizeof(int), compare); }

int maxCount(int *banned, int bannedSize, int n, int maxSum) {
  sortIntegers(banned, bannedSize);

  int *chosen = (int *)calloc(n, sizeof(int));
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (j < bannedSize && i + 1 == banned[j]) {
      j++;
      continue;
    }

    chosen[i] = i + 1;
  }

  sortIntegers(chosen, n);

  int sum = 0;
  int totalNonZero = 0;
  for (int i = 0; i < n; i++) {
    if (chosen[i] != 0) {
      totalNonZero++;
    }

    sum += chosen[i];
  }

  int i = n - 1;
  while (sum > maxSum) {
    sum -= chosen[i];
    totalNonZero--;
    i--;
  }

  return totalNonZero;
}
// @leet end
