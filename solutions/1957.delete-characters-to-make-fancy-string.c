#include <stdlib.h>
#include <string.h>

// @leet start
char* makeFancyString(char* s) {
  int resultLen = 0;
  int entryLen = strlen(s);

  char* result = malloc((entryLen + 1) * sizeof(char));
  char current = s[0];
  int count = 1;

  for (int i = 1; i < entryLen; i++) {
    if (count < 3) {
      result[resultLen++] = current;
    }

    if (s[i] == current) {
      count++;
      continue;
    }

    current = s[i];
    count = 1;
  }

  if (count < 3) {
    result[resultLen++] = current;
  }

  result[resultLen] = '\0';
  return result;
}
// @leet end
