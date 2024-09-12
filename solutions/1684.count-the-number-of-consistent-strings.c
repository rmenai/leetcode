#include <stdlib.h>
#include <stdbool.h>

// @leet start
int countConsistentStrings(char * allowed, char ** words, int wordsSize){
  int count = 0;

  for (int i = 0; i < wordsSize; i++) {
    char *word = words[i];
    bool is_allowed = true;

    for (int j = 0; word[j] != '\0'; j++) {
      bool is_letter_allowed = false;

      for (int k = 0; allowed[k] != '\0'; k++) {
        if (word[j] == allowed[k]) {
          is_letter_allowed = true;
          break;
        }
      }

      if (!is_letter_allowed) {
        is_allowed = false;
        break;
      }
    }

    if (is_allowed) {
      count++;
    }
  }

  return count;
}
// @leet end
