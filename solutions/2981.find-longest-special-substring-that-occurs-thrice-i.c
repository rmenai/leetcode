#include <stdbool.h>
#include <string.h>

// @leet start
int maximumLength(char* s) {
  int length = strlen(s);
  int frequency[26];

  for (int k = length - 2; k >= 1; k--) {
    int iterations = length - k + 1;

    for (int i = 0; i < 26; i++) {
      frequency[i] = 0;
    }

    for (int i = 0; i < iterations; i++) {
      bool brocken = false;
      char c = s[i];
      for (int j = i; j < k + i; j++) {
        if (s[j] != c) {
          brocken = true;
          break;
        }
      }

      if (!brocken) {
        frequency[c - 'a']++;
      }
    }

    for (int i = 0; i < 26; i++) {
      if (frequency[i] >= 3) {
        return k;
      }
    }
  }

  return -1;
}
// @leet end
