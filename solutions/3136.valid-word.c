#include <stdbool.h>
#include <string.h>

// @leet start
bool isValid(char* word) {
  char vowels[] = "aeiouAEIOU";
  char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
  char digits[] = "0123456789";

  if (strlen(word) < 3) {
    return false;
  }

  bool hasVowel = false;
  bool hasConsonant = false;

  for (int i = 0; word[i] != '\0'; i++) {
    bool isEnglish = false;

    for (int j = 0; vowels[j] != '\0'; j++) {
      if (word[i] == vowels[j]) {
        hasVowel = true;
        isEnglish = true;
      }
    }

    for (int j = 0; consonants[j] != '\0'; j++) {
      if (word[i] == consonants[j]) {
        hasConsonant = true;
        isEnglish = true;
      }
    }

    for (int j = 0; digits[j] != '\0'; j++) {
      if (word[i] == digits[j]) {
        isEnglish = true;
      }
    }

    if (!isEnglish) {
      return false;
    }
  }

  return hasVowel && hasConsonant;
}
// @leet end
