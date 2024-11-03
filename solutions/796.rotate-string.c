#include <stdbool.h>

// @leet start
bool areEqualFromIndex(char* s, char* goal, int i) {
  int j = 0;

  for (int k = i; s[k] != '\0'; k++) {
    if (s[k] != goal[j++]) {
      return false;
    }
  }

  for (int k = 0; k < i; k++) {
    if (s[k] != goal[j++]) {
      return false;
    }
  }

  return true;
}

bool rotateString(char* s, char* goal) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == goal[0]) {
      if (areEqualFromIndex(s, goal, i)) {
        return true;
      }
    }
  }

  return false;
}
// @leet end
