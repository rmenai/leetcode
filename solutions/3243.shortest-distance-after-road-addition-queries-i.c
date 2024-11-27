#include <stdlib.h>

// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *shortestDistanceAfterQueries(int n, int **queries, int queriesSize, int *queriesColSize, int *returnSize) {
  int *answer = (int *)malloc(queriesSize * sizeof(int));
  int *shortcuts = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    shortcuts[i] = i + 1;
  }

  for (int i = 0; i < queriesSize; i++) {
    int *query = queries[i];

    if (query[1] > shortcuts[query[0]]) {
      shortcuts[query[0]] = query[1];
    }

    int pathLength = 0;
    int j = 0;
    while (j < n - 1) {
      j = shortcuts[j];
      pathLength++;
    }

    answer[i] = pathLength;
  }

  free(shortcuts);
  *returnSize = queriesSize;
  return answer;
}
// @leet end
