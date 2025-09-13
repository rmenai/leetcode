#include <stdbool.h>
#include <stdlib.h>

// @leet start
const char* VOWELS = "aeiou";
const char* CONSONENTS = "bcdfghjklmnpqrstvwxyz";

int maxFreqSum(char* s) {
  int* count = (int*)calloc(256, sizeof(int));

  for (int i = 0; s[i] != '\0'; i++) {
    count[s[i]]++;
  }

  int maxVowels = -1;
  int maxConsonents = -1;

  for (int i = 0; VOWELS[i] != '\0'; i++) {
    if (count[VOWELS[i]] > maxVowels) {
      maxVowels = count[VOWELS[i]];
    }
  }

  for (int i = 0; CONSONENTS[i] != '\0'; i++) {
    if (count[CONSONENTS[i]] > maxConsonents) {
      maxConsonents = count[CONSONENTS[i]];
    }
  }

  free(count);
  return maxVowels + maxConsonents;
}
// @leet end
