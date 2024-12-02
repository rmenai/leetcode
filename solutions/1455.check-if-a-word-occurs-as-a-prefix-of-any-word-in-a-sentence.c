#include <stdbool.h>
#include <string.h>

// @leet start
int isPrefixOfWord(char* sentence, char* searchWord) {
  int wordLength = strlen(searchWord);
  int wordIndex = 0;
  int wordCount = 1;

  bool isPrefix = true;
  for (int i = 0; sentence[i] != '\0'; i++) {
    if (sentence[i] == ' ') {
      isPrefix = true;
      wordIndex = 0;
      wordCount++;
      continue;
    }

    if (isPrefix && sentence[i] == searchWord[wordIndex]) {
      wordIndex++;

      if (wordIndex == wordLength) {
        return wordCount;
      }

      continue;
    }

    wordIndex = 0;
    isPrefix = false;
  }

  return -1;
}
// @leet end
