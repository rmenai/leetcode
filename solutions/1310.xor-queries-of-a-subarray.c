#include <stdlib.h>

// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
  int* answer = malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; i++) {
    int *query = queries[i];
    int result = arr[query[0]];

    for (int j = query[0] + 1; j <= query[1]; j++) {
      result ^= arr[j];
    }

    answer[i] = result;
  }

  *returnSize = queriesSize;
  return answer;
}
// @leet end
