#include <stdlib.h>

// @leet start
int firstCompleteIndex(int *arr, int arrSize, int **mat, int matSize, int *matColSize) {
  int *checks_i = (int *)malloc(matSize * sizeof(int));
  int *checks_j = (int *)malloc(matColSize[0] * sizeof(int));

  for (int i = 0; i < matSize; i++) {
    checks_i[i] = 0;
  }

  for (int j = 0; j < matColSize[0]; j++) {
    checks_j[j] = 0;
  }

  int **indices = (int **)malloc((arrSize + 1) * sizeof(int *));

  for (int i = 0; i < matSize; i++) {
    for (int j = 0; j < matColSize[0]; j++) {
      indices[mat[i][j]] = (int *)malloc(2 * sizeof(int *));
      indices[mat[i][j]][0] = i;
      indices[mat[i][j]][1] = j;

      checks_i[i]++;
      checks_j[j]++;
    }
  }

  for (int k = 0; k < arrSize; k++) {
    int i = indices[arr[k]][0];
    int j = indices[arr[k]][1];

    checks_i[i]--;
    checks_j[j]--;

    if (checks_i[i] == 0 || checks_j[j] == 0) {
      return k;
    }
  }

  free(checks_i);
  free(checks_j);

  for (int k = 0; k < arrSize; k++) {
    free(indices[k]);
  }

  free(indices);
  return -1;
}
// @leet end
