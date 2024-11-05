#include <string.h>

// @leet start
int minChanges(char* s) {
  int lenghtOfString = strlen(s); 
  int numberOfChanges = 0;

  for (int i = 0; i < lenghtOfString; i += 2) {
    if (s[i] != s[i + 1]) {
      numberOfChanges++;
    }
  }

  return numberOfChanges;
}
// @leet end
