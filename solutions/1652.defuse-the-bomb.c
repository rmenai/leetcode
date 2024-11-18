#include <stdbool.h>
#include <stdlib.h>

// @leet start
int* decrypt(int* code, int codeSize, int k, int* returnSize) {
  int* decryptedCode = (int*)calloc(codeSize, sizeof(int));
  *returnSize = codeSize;

  if (k == 0) {
    return decryptedCode;
  }

  int start = 1;
  int end = k;
  int sum = 0;

  if (k < 0) {
    k = -k;
    start = codeSize - k;
    end = codeSize - 1;
  }

  for (int i = start; i <= end; i++) {
    sum += code[i];
  }

  for (int i = 0; i < codeSize; i++) {
    decryptedCode[i] = sum;

    sum -= code[start % codeSize];

    start++;
    end++;

    sum += code[end % codeSize];
  }

  return decryptedCode;
}
// @leet end
