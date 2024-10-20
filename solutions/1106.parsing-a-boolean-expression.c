#include <stdlib.h>
#include <stdbool.h>

// @leet start
bool and(bool a, bool b) {
  return a && b;
}

bool or(bool a, bool b) {
  return a || b;
}

bool parseBoolExprRecursive(char *expression, int start, int end) {
  if (expression[start] == 't') return true;
  if (expression[start] == 'f') return false;
  if (expression[start] == '!') return !parseBoolExprRecursive(expression, start + 2, end - 1);

  bool (*operation)(bool a, bool b);
  bool result;

  int paranthesesCount = 0;
  int currentWordIndex = start + 2;

  if (expression[start] == '&') {
    operation = &and;
    result = true;
  }
  if (expression[start] == '|') {
    operation = &or;
    result = false;
  }

  for (int i = start + 2; i <= end; i++) {
    if (expression[i] == '(') paranthesesCount++;
    if (expression[i] == ')') paranthesesCount--;

    if (paranthesesCount == 0 && expression[i] == ',' || paranthesesCount == -1) {
      result = operation(result, parseBoolExprRecursive(expression, currentWordIndex, i - 1));
      currentWordIndex = i + 1;
    }
  }

  return result;
}

bool parseBoolExpr(char* expression) {
  int length = 0;
  while (expression[length] != '\0') length++;

  return parseBoolExprRecursive(expression, 0, length - 1);
}
// @leet end
