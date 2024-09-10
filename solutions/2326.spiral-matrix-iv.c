#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

// @leet start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
  int** matrix = malloc(m * sizeof(int*));

  *returnSize = m;
  *returnColumnSizes = malloc(m * sizeof(int));

  // Allocate matrix space
  for (int i = 0; i < m; i++) {
    matrix[i] = malloc(n * sizeof(int));
    (*returnColumnSizes)[i] = n;
  }

  // Fill matrix with default value -1
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      matrix[i][j] = -1;
    }
  }

  int i = 0, j = 0, direction = 1;
  struct ListNode* cur = head;

  // Fill matrix with values
  while (cur != NULL) {
    // Set cell value
    if (direction == 1) {
      if (j + 1 == n || matrix[i][j + 1] != -1) {
        direction = 2;
        continue;
      }

      matrix[i][j++] = cur->val;
      cur = cur->next;
    }

    if (direction == 2) {
      if (i + 1 == m || matrix[i + 1][j] != -1) {
        direction = 3;
        continue;
      }

      matrix[i++][j] = cur->val;
      cur = cur->next;
    }

    if (direction == 3) {
      if (j == 0 || matrix[i][j - 1] != -1) {
        direction = 4;
        continue;
      }

      matrix[i][j--] = cur->val;
      cur = cur->next;
    }

    if (direction == 4) {
      if (i == 0 || matrix[i - 1][j] != -1) {
        direction = 1;
        continue;
      }

      matrix[i--][j] = cur->val;
      cur = cur->next;
    }
  }

  return matrix;
}
// @leet end
