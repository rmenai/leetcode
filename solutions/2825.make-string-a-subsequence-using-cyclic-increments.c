#include <stdbool.h>

// @leet start
bool canMakeSubsequence(char* str1, char* str2) {
  int j = 0;
  for (int i = 0; str1[i] != '\0';i++) {
    char letter = str1[i];
    char next = str1[i] == 'z' ? 'a' : str1[i] + 1;

    if (str2[j] == letter || str2[j] == next) {
      j++;
    }

    if (str2[j] == '\0') {
      return true;
    }
  }

  return false;
}
// @leet end
