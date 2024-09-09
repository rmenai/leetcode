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
  *returnSize = m;
  *returnColumnSizes = malloc(m * sizeof(int));

  int** matrix = malloc(m * sizeof(int*));
  for (int i = 0; i < m; i++) {
    matrix[i] = malloc(n * sizeof(int));
    (*returnColumnSizes)[i] = n;
  }

  int total = m * n, count = 0, round = 0;
  int m_bound = m, n_bound = n;
  while (count < total) {
    int i = round, j;
    for (j = round; j < n_bound && count < total; j++) {
      if (head) {
        matrix[i][j] = head->val;
        head = head->next;
      } else {
        matrix[i][j] = -1;
      }
      count += 1;
    }

    j--;

    for (i = round + 1; i < m_bound && count < total; i++) {
      if (head) {
        matrix[i][j] = head->val;
        head = head->next;
      } else {
        matrix[i][j] = -1;
      }
      count += 1;
    }

    i--;

    for (j = j - 1; j >= round && count < total; j--) {
      if (head) {
        matrix[i][j] = head->val;
        head = head->next;
      } else {
        matrix[i][j] = -1;
      }
      count += 1;
    }

    j++;
    round += 1;

    for (i = i - 1; i >= round && count < total; i--) {
      if (head) {
        matrix[i][j] = head->val;
        head = head->next;
      } else {
        matrix[i][j] = -1;
      }
      count += 1;
    }

    m_bound--;
    n_bound--;
  }

  return matrix;
}
// /**
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  */
// int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
//   int** matrix = malloc(m * sizeof(int*));
//
//   *returnSize = m;
//   *returnColumnSizes = malloc(m * sizeof(int));
//
//   // Allocate matrix space
//   for (int i = 0; i < m; i++) {
//     matrix[i] = malloc(n * sizeof(int));
//     (*returnColumnSizes)[i] = n;
//   }
//
//   // Fill matrix with default value -1
//   for (int i = 0; i < m; i++) {
//     for (int j = 0; j < n; j++) {
//       matrix[i][j] = -1;
//     }
//   }
//
//   int i = 0, j = 0;
//   struct ListNode* cur = head;
//
//   matrix[1][1] = 1;
//   // while (cur != NULL) {
//   //   matrix[i][j] = 0;
//   //   cur = cur->next;
//   //
//   //   if (i - 1 < m && matrix[i + 1][j] == -1)
//   //     i++;
//   //   else {
//   //     j++;
//   //     i = 0;
//   //   }
//   // }
//
//   return matrix;
// }
// @leet end
