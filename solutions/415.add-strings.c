#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// @leet start
char* addStrings(char* num1, char* num2) {
  int n = strlen(num1);
  int m = strlen(num2);

  int a = 0;
  int k = 1;
  for (int i = n - 1; i >= 0; i--) {
    a += (num1[i] - '0') * k;
    k *= 10;
  }

  k = 1;
  for (int i = m - 1; i >= 0; i--) {
    a += (num2[i] - '0') * k;
    k *= 10;
  }

  int length = snprintf(NULL, 0, "%d", a);
  char* str = malloc(length + 1);
  sprintf(str, "%d", a);
  return str;
}
// @leet end
