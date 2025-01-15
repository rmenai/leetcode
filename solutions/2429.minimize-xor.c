#include <stdint.h>

// @leet start
int count_bits(int num) {
  int count = 0;

  for (int _ = 0; _ < 32; _++) {
    count += num & 1;
    num >>= 1;
  }

  return count;
}

int minimizeXor(int num1, int num2) {
  int count1 = count_bits(num1);
  int count2 = count_bits(num2);

  int x = num1;
  if (count1 == count2) {
    return x;
  }

  if (count2 > count1) {
    unsigned int filter = 1;

    for (int i = 0; i < 32 && count2 > count1; i++) {
      if ((x & filter) == 0) {
        x |= filter;
        count1++;
      }

      filter <<= 1;
    }
  }

  if (count2 < count1) {
    unsigned int filter = 1;

    for (int i = 0; i < 32 && count2 < count1; i++) {
      if ((x & filter) > 0) {
        x ^= filter;
        count2++;
      }

      filter <<= 1;
    }
  }

  return x;
}
// @leet end
