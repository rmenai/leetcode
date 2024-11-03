#include <stdbool.h>
#include <string.h>

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

void buildKMPTable(char* pattern, int* table, int m) {
  int j = 0;
  table[0] = 0;

  for (int i = 1; i < m; i++) {
    if (pattern[i] == pattern[j]) {
      j++;
      table[i] = j;
    } else if (j > 0) {
    }
  }
}

bool KMPSearch(char* s, char* pattern) {
  int len_pattern = strlen(pattern);
  int len_s = strlen(s);
  int table[len_pattern];

  buildKMPTable(pattern, table, len_pattern);

  int i = 0;
  int j = -1;

  while (j + 1 < len_pattern || i < len_s) {
    if (s[i] == pattern[j + 1]) {
      i++;
      j++;
    } else {
      if (j == -1) {
        i++;
      } else {
        j = table[j];
      }
    }
  }

  if (j + 1 != len_pattern) {
    return false;
  }

  return true;
}

bool rotateString(char* s, char* goal) {
  int len_s = strlen(s);
  int len_goal = strlen(goal);

  if (len_s != len_goal) {
    return false;
  }

  char s2[2 * len_s + 1];

  strcpy(s2, s);
  strcpy(s2, s);

  return KMPSearch(s2, goal);
}
