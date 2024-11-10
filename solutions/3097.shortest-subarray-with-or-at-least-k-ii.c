#include <stdbool.h>
#include <stdlib.h>

// @leet start
void addBits(int *bits, int num) {
  for (int i = 0; i < 32; i++) {
    if (num % 2 == 1) {
      bits[i]++;
    }

    num >>= 1;
  }
}

void removeBits(int *bits, int num) {
  for (int i = 0; i < 32; i++) {
    if (num % 2 == 1) {
      bits[i]--;
    }

    num >>= 1;
  }
}

bool bitsEqualTo(int *bits, int k) {
  int num = 0;
  for (int i = 31; i >= 0; i--) {
    num <<= 1;
    if (bits[i] > 0) {
      num += 1;
    }
  }

  if (num >= k) {
    return true;
  }

  return false;
}

bool isSubarraySpecial(int *nums, int numsSize, int n, int k) {
  int *bitCount = calloc(32, sizeof(int));

  for (int i = 0; i < n; i++) {
    addBits(bitCount, nums[i]);
  }

  if (bitsEqualTo(bitCount, k)) {
    free(bitCount);
    return true;
  }

  for (int i = n; i < numsSize; i++) {
    removeBits(bitCount, nums[i - n]);
    addBits(bitCount, nums[i]);

    if (bitsEqualTo(bitCount, k)) {
      free(bitCount);
      return true;
    }
  }

  free(bitCount);
  return false;
}

int minimumSubarrayLength(int *nums, int numsSize, int k) {
  int left = 1;
  int right = numsSize;

  int minLength = -1;
  while (left <= right) {
    int mid = (right + left) / 2;
    if (isSubarraySpecial(nums, numsSize, mid, k)) {
      minLength = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return minLength;
}
// @leet end
