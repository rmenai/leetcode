#include <stdlib.h>

// @leet start
int* leftmostBuildingQueries(int* heights, int heightsSize, int** queries, int queriesSize, int* queriesColSize,
                             int* returnSize) {
  int* ans = (int*)malloc(queriesSize * sizeof(int));

  for (int i = 0; i < queriesSize; i++) {
    ans[i] = -1;

    int a = queries[i][0];
    int b = queries[i][1];

    int max = a > b ? a : b;

    for (int j = max; j < heightsSize; j++) {
      if (a < j && heights[a] == heights[j] || b < j && heights[b] == heights[j]) {
        continue;
      }

      if (heights[j] >= heights[a] && heights[j] >= heights[b]) {
        ans[i] = j;
        break;
      }
    }
  }

  *returnSize = queriesSize;
  return ans;
}
// @leet end
