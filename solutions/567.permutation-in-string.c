#include <stdbool.h>
#include <stdlib.h>
#include <string>

// @leet start
bool isMatch(int *s1Count, int *s2Count) {
  bool isEqual = true;
  for (int i = 0; i < 26; i++) {
    if (s1Count[i] != s2Count[i]) {
      isEqual = false;
      break;
    }
  }

  return isEqual;
}

bool checkInclusion(char* s1, char* s2) {
  int s1Count[26] = { 0 };
  int s2Count[26] = { 0 };

  int charLen = 0;

  // Computer s1 signature
  for (charLen = 0; s1[charLen] != '\0'; charLen++) {
    if (s2[charLen] == '\0') {
      return false;
    }

    s1Count[s1[charLen] - 'a']++;
    s2Count[s2[charLen] - 'a']++;
  }

  if (isMatch(s1Count, s2Count)) {
    return true;
  }

  // Update signature
  for (int i = charLen; s2[i] != '\0'; i++) {
    s2Count[s2[i] - 'a']++;
    s2Count[s2[i - charLen] - 'a']--;

    if (isMatch(s1Count, s2Count)) {
      return true;
    }
  }

  return false;
}
// @leet end
