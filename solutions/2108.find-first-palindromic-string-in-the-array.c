#include <stdbool.h>
#include <string.h>

// @leet start
char* firstPalindrome(char** words, int wordsSize) {
  for (int i = 0; i < wordsSize; i++) {
    bool isPalindrome = true;
    int length = strlen(words[i]);

    for (int j = 0; j < length; j++) {
      if (words[i][j] != words[i][length - j - 1]) {
        isPalindrome = false;
      }
    }

    if (isPalindrome) {
      return words[i];
    }
  }

  return "";
}
// @leet end
