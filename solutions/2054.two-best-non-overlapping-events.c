#include <stdlib.h>

// @leet start
int comp(const void *a, const void *b) {
  int *first = *(int **)a;
  int *second = *(int **)b;
  return second[2] - first[2];
}

int removeDuplicate(int **arr, int n) {
  if (n == 0) return 0;

  int j = 0;
  for (int i = 1; i < n; i++) {
    if (!(arr[i][0] == arr[j][0] && arr[i][1] == arr[j][1] && arr[i][2] == arr[j][2])) {
      arr[++j] = arr[i]; 
    }
  }

  return j + 1;
}

int maxTwoEvents(int **events, int eventsSize, int *eventsColSize) {
  qsort(events, eventsSize, sizeof(int *), comp);
  eventsSize = removeDuplicate(events, eventsSize);

  int max = events[0][2];
  for (int i = 0; i < eventsSize - 1; i++) {
    if (2 * events[i][2] <= max) break;
    for (int j = i + 1; j < eventsSize; j++) {
      if (events[i][1] < events[j][0] || events[j][1] < events[i][0]) {
        int sum = events[i][2] + events[j][2];
        if (sum > max) max = sum;
        break;
      }
    }
  }

  return max;
}
// @leet end
