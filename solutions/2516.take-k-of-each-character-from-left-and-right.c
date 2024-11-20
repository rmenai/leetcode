#include <stdlib.h>
#include <string.h>

// @leet start
int takeCharacters(char *s, int k) {
  int length = strlen(s);
  int *freq = (int *)calloc(3, sizeof(int));

  for (int i = 0; i < length; i++) {
    freq[s[i] - 'a']++;
  }

  if (freq[0] < k || freq[1] < k || freq[2] < k) {
    free(freq);
    return -1;
  }

  int left = 0;
  int maxWindow = 0;
  int currentWindow[3] = {0, 0, 0};
  for (int right = 0; right < length; right++) {
    currentWindow[s[right] - 'a']++;
    while (left <= right &&
           (freq[0] - currentWindow[0] < k || freq[1] - currentWindow[1] < k || freq[2] - currentWindow[2] < k)) {
      currentWindow[s[left] - 'a']--;
      left += 1;
    }

    if (right - left + 1 > maxWindow) {
      maxWindow = right - left + 1;
    }
  }

  free(freq);
  return length - maxWindow;
}
// @leet end
