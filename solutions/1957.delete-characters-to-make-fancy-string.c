#include <stdlib.h>
#include <string.h>

// @leet start
char* makeFancyString(char* s) {
  int entryLen = strlen(s);
  int resultLen = 0;

  char* result = malloc((entryLen + 1) * sizeof(char));
  char current = s[0];
  int count = 1;

  for (int i = 1; i < entryLen; i++) {
    if (s[i] == current) {
      count++;
      if (i + 1 < entryLen) continue;
    };

    if (count >= 2) result[resultLen++] = current;
    result[resultLen++] = current;

    current = s[i];
    count = 1;
  }

  if (result[resultLen - 1] != current) {
    result[resultLen++] = current;
  }

  result[resultLen] = '\0';
  return result;
}
// @leet end
