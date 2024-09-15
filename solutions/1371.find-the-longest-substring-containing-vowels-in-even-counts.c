#include <stdbool.h>
#include <stdlib.h>

// @leet start
int getIndex(char s) {
  if (s == 'a') return 0;
  if (s == 'e') return 1;
  if (s == 'i') return 2;
  if (s == 'o') return 3;
  if (s == 'u') return 4;

  return -1;
}

bool isEven(char *s, int i, int j) {
  int *count = calloc(5, sizeof(int));
  for (int k = i; k < j; k++) {
    int charIndex = getIndex(s[k]);

    if (charIndex != -1) {
      count[charIndex]++;
    }
  }

  for (int k = 0; k < 5; k++) {
    if (count[k] % 2 != 0) {
      return false;
    }
  }

  return true;
}

int findTheLongestSubstring(char *s) {
  int size = 0;
  int longestSize = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    size++;
  }

  // Loop through all substrings
  for (int j = 0; j < size; j++) {
    for (int i = j; i < size; i++) {
      if (isEven(s, j, i + 1)) {
        if (i - j + 1 > longestSize) {
          longestSize = i - j + 1;
        }
      }
    }
  }

  return longestSize;
}
// @leet end
