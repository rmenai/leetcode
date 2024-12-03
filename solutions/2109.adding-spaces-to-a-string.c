#include <stdlib.h>
#include <string.h>

// @leet start
char* addSpaces(char* s, int* spaces, int spacesSize) {
  int stringSize = strlen(s);
  int stringIndex = 0;
  int spacesIndex = 0;

  char* newString = (char*)malloc((stringSize + spacesSize + 1) * sizeof(char));
  for (int i = 0; s[i] != '\0'; i++) {
    if (spacesIndex < spacesSize && i == spaces[spacesIndex]) {
      newString[stringIndex++] = ' ';
      spacesIndex++;
    }

    newString[stringIndex++] = s[i];
  }

  newString[stringSize + spacesSize] = '\0';
  return newString;
}
// @leet end
