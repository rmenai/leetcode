#include <stdlib.h>

// @leet start
int findChampion(int n, int** edges, int edgesSize, int* edgesColSize) {
  int *teams = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < edgesSize; i++) {
    int looser = edges[i][1];
    teams[looser] = -1;
  }

  int winnerCount = 0;
  int candidateWinner = 0;
  for (int i = 0; i < n; i++) {
    if (teams[i] == 0) {
      candidateWinner = i;
      winnerCount++;
    }
  }

  if (winnerCount == 1) {
    return candidateWinner;
  }

  return -1;
}
// @leet end
