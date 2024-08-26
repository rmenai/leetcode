// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  for (int i = 0; i < numsSize; i++) {
    for (int j = 0; j < numsSize; j++) {
      if (nums[i] + nums[j] == target) {
        int *result = malloc(2 * sizeof(int));
        *returnSize = 2;
        result[0] = i;
        result[1] = j;

        return result;
      }
    }
  }
  return 0;
}
// @leet end
