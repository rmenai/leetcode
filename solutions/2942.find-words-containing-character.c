#include <stdbool.h>
#include <stdlib.h>

// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
  int* result = (int*)malloc(wordsSize * sizeof(int));
  int k = 0;

  for (int i = i; i < wordsSize; i++) {
    bool contains = false;

    for (int j = 0; words[i][j] != '\0'; j++) {
      if (words[i][j] == x) {
        contains = true;
      }
    }

    if (contains) {
      result[k] = i;
      k++;
    }
  }

  *returnSize = k;
  return result;
}
// @leet end
