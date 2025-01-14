#include <stdint.h>
#include <stdlib.h>

// @leet start
int count_bits(uint64_t num) {
  int count = 0;
  for (int _ = 0; _ < 64; _++) {
    count += num & 1;
    num >>= 1;
  }

  return count;
}

int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
  int* result = (int*)malloc(ASize * sizeof(int));
  *returnSize = ASize;

  uint64_t a_mask = 0;
  uint64_t b_mask = 0;

  for (int i = 0; i < ASize; i++) {
    a_mask |= 1 << A[i];
    b_mask |= 1 << B[i];

    result[i] = count_bits(a_mask && b_mask);
  }

  return result;
}
// @leet end
