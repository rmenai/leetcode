#include <stdlib.h>
#include <string.h>

// @leet start
char* compressedString(char* word) {
  int word_len = strlen(word);
  char *compressed = malloc((2 * word_len + 1) * sizeof(char));
  char c = word[0];

  int count = 1;
  int j = 0;
  for (int i = 1; i < word_len; i++) {
    if (word[i] == c && count < 9) {
      count++;
    } else {
      compressed[j++] = '0' + count;
      compressed[j++] = c;

      c = word[i];
      count = 1;
    }
  }

  compressed[j++] = '0' + count;
  compressed[j++] = c;

  compressed[j] = '\0';
  return compressed;
}
// @leet end
