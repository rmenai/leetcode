// @leet start
int minSubArrayLen(int target, int* nums, int numsSize) {
  int minLength = 0;
  int culcutativeSum = 0;

  int i = 0;
  int j = 0;
  while (i < numsSize || culcutativeSum >= target) {
    if (culcutativeSum < target) {
      culcutativeSum += nums[i];
      i++;
    } else {
      int length = i - j;
      if (length < minLength || minLength == 0){
        minLength = length;
      }

      culcutativeSum -= nums[j];
      j++;
    }
  }

  return minLength;
}
// @leet end
