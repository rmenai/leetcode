#include <stdbool.h>

// @leet start
bool doesAliceWin(char* s) {
  for (int i = 0; s[i] != '\0'; i++) {
    // Vowels bitmask: 0b00000000000100000100000100010001
    if ((0x104111 >> (s[i] - 97)) & 1) {
      return true;
    }
  }

  return false;
}
// @leet end
