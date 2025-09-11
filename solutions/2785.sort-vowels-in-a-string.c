#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// @leet start
const char VOWELS[] = "AEIOUaeiou";

char *sortVowels(char *s) {
  int n = strlen(s);

  int *count = (int *)calloc(256, sizeof(int));
  bool *isVowel = (bool *)calloc(n + 1, sizeof(bool));

  for (int i = 0; i < n; i++) {
    count[s[i]]++;

    for (int j = 0; VOWELS[j] != '\0'; j++) {
      if (s[i] == VOWELS[j]) {
        isVowel[i] = true;
        break;
      }
    }
  }

  char *result = (char *)malloc((n + 1) * sizeof(char));

  for (int i = 0; i < n; i++) {
    result[i] = s[i];

    if (isVowel[i]) {
      for (int j = 0; VOWELS[j] != '\0'; j++) {
        if (count[VOWELS[j]] > 0) {
          result[i] = VOWELS[j];
          count[VOWELS[j]]--;
          break;
        }
      }
    }
  }

  result[n] = '\0';

  free(count);
  free(isVowel);
  return result;
}
// @leet end
