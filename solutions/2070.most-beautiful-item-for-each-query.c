#include <stdlib.h>

// @leet start
int priceCompare(const void* first, const void* second) {
  int* item1 = *(int**)first;
  int* item2 = *(int**)second;

  return item1[0] - item2[0];
}

int queryCompare(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int* maximumBeauty(int** items, int itemsSize, int* itemsColSize, int* queries, int queriesSize, int* returnSize) {
  qsort(items, itemsSize, itemsColSize[0] * sizeof(int), priceCompare);
  qsort(queries, queriesSize, sizeof(int), queryCompare);

  int** sortedItems = items;
  int* sortedQueries = queries;

  int* answer = malloc(sizeof(int) * queriesSize);

  int j = 1;
  int max = sortedItems[0][1];

  for (int i = 0; i < queriesSize; i++) {
    while (sortedItems[j][0] <= sortedQueries[i] && j < queriesSize) {
      if (sortedItems[j][1] > max) {
        max = sortedItems[j + 1][1];
      }

      j++;
    }

    answer[i] = max;
  }

  return answer;
}
// @leet end
