#include <stdlib.h>
#include <stdbool.h>

// @leet start
bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
  bool *answer = (bool *)malloc(queriesSize * sizeof(bool));

  int *prefix = (int *)malloc(numsSize * sizeof(int));
  prefix[0] = 0;

  for (int i = 1; i < numsSize; i++) {
    prefix[i] = prefix[i - 1] + (int)((nums[i] % 2) == (nums[i - 1] % 2));
  }

  for (int k = 0; k < queriesSize; k++) {
    int *query = queries[k];
    answer[k] = prefix[query[1]] - prefix[query[0]] == 0;
  }

  free(prefix);

  *returnSize = queriesSize;
  return answer;
}
// @leet end
