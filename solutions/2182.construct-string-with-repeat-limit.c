#include <stdlib.h>
#include <string.h>

// @leet start
int findNext(int *a, int start) {
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

  char *newString = (char *)malloc((length + 1) * sizeof(char));

  int i = findNext(frequency, 25);
  int j = 0;
  while (i >= 0) {
    int count = frequency[i] <= repeatLimit ? frequency[i] : repeatLimit;

    for (int _ = 0; _ < count; _++) {
      newString[j++] = 'a' + i;
      frequency[i]--;
    }

    if (frequency[i] > 0) {
      int k = findNext(frequency, i - 1);
      if (k == -1) break;

      newString[j++] = 'a' + k;
      frequency[k]--;
    } else {
      i = findNext(frequency, i - 1);
    }
  }

  newString[j] = '\0';
  return newString;
}
// @leet end
