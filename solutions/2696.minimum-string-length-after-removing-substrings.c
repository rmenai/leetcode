#include <stdbool.h>
#include <stdlib.h>

// @leet start
int minLength(char* s) {
  // Calculate string size
  int size = 0;
  int changesCount = 0;
  for (size = 0; s[size] != '\0'; size++);

  while (true) {
    int pastChar = -1;
    bool isChanged = false;
    for (int i = 0; i < size; i++) {
      if (s[i] == ' ') {
        continue;
      }

      if (pastChar == -1 || s[pastChar] == ' ') {
        pastChar = i;
        continue;
      }

      if ((s[pastChar] == 'A' && s[i] == 'B') || (s[pastChar] == 'C' && s[i] == 'D')) {
        s[pastChar] = ' ';
        s[i] = ' ';

        isChanged = true;
        changesCount++;
      }

      pastChar = i;
    }

    if (!isChanged) {
      return size - 2 * changesCount;
    }
  }
}
// @leet end
