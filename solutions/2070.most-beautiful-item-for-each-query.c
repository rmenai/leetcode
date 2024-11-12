#include <stdlib.h>

// @leet start
int priceCompare(const void* a, const void* b) {
  int* item1 = *(int**)a;
  int* item2 = *(int**)b;
  if (item1[0] == item2[0]) return item1[1] - item2[1];
  return item1[0] - item2[0];
}

int* maximumBeauty(int** items, int itemsSize, int* itemsColSize, int* queries, int queriesSize, int* returnSize) {
  qsort(items, itemsSize, sizeof(int*), priceCompare);

  int* maxBeauty = (int*)malloc(itemsSize * sizeof(int));

  maxBeauty[0] = items[0][1];
  for (int i = 1; i < itemsSize; i++) {
    maxBeauty[i] = (maxBeauty[i - 1] > items[i][1]) ? maxBeauty[i - 1] : items[i][1];
  }

  int* answer = (int*)malloc(queriesSize * sizeof(int));

  for (int i = 0; i < queriesSize; i++) {
    int left = 0;
    int right = itemsSize - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (items[mid][0] <= queries[i]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    answer[i] = (right >= 0) ? maxBeauty[right] : 0;
  }

  free(maxBeauty);
  *returnSize = queriesSize;
  return answer;
}
// @leet end
