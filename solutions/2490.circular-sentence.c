#include <stdbool.h>

// @leet start
bool isCircularSentence(char* sentence) {
  int length;

  for (length = 0; sentence[length] != '\0'; length++) {
    if (sentence[length] == ' ') {
      if (sentence[length - 1] != sentence[length + 1]) {
        return false;
      }
    }
  }

  return sentence[0] == sentence[length - 1];
}
// @leet end
