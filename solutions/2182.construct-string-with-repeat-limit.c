#include <stdlib.h>
#include <string.h>

// @leet start
int findNext(int *a, int start, int length) {
  for (int i = start; i >= 0; i--) {
    if (a[i] > 0) {
      return i;
    }
  }

  return -1;
}

char *repeatLimitedString(char *s, int repeatLimit) {
  int frequency[26];
  int length = strlen(s);

  for (int i = 0; i < length; i++) {
    frequency[s[i] - 'a']++;
  }

  char *newString = (char *)malloc((length + 8) * sizeof(char));

  int i = findNext(frequency, 25, 26);
  int j = 0;
  int count = 0;
  while (i >= 0) {
    while (count < repeatLimit) {
      if (frequency[i] == 0) {
        count = 0;
        break;
      }

      newString[j++] = 'a' + i;
      frequency[i]--;
      count++;
    }

    if (frequency[i] == 0) {
      i = findNext(frequency, i, 26);
      count = 0;
    } else {
      int k = findNext(frequency, i, 26);
      if (k != -1) {
        newString[j++] = 'a' + k;
        frequency[k]--;
      }

      count = 0;
    }
  }

  newString[j] = '\0';
  return newString;
}
// @leet end
