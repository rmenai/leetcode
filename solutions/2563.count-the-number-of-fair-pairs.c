// @leet start
long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
  int count = 0;
  for (int i = 0; i < numsSize - 1; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      int sum = nums[i] + nums[j];
      if (lower <= sum && sum <= upper) {
        count++;
      }
    }
  }

  return count;
}
// @leet end
