#include <stdbool.h>
#include <string.h>

// @leet start
void swap(char *chars, int i, int j) {
  char temp = chars[i];
  chars[i] = chars[j];
  chars[j] = temp;
}

void applyGravity(char *chars, int length) {
  int lastRightPiece = -1;

  for (int i = 0; i < length - 1; i++) {
    if (chars[i] == 'R') {
      lastRightPiece = i;
    }

    if (chars[i] == 'L') {
      swap(chars, lastRightPiece + 1, i);
      lastRightPiece++;
    }
  }


  int lastLeftPiece = length;

  for (int i = length - 1; i > 0; i--) {
    if (chars[i] == 'L') {
      lastLeftPiece = i;
    }

    if (chars[i] == 'R') {
      swap(chars, lastLeftPiece - 1, i);
      lastLeftPiece--;
    }
  }
}

// DOES NOT WORK
bool canChange(char* start, char* target) {
  int length = strlen(start);
  if (length != strlen(target)) {
    return false;
  }


  applyGravity(start, length);
  applyGravity(target, length);

  for (int i = 0; i < length; i++) {
    if (start[i] != target[i]) {
      return false;
    }
  }

  return true;
}
// @leet end
