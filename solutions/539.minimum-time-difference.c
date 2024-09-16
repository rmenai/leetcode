#include <stdlib.h>
#include <stdio.h>

// @leet start

int timeToMinutes(char *time) {
  int hours, minutes;
  scanf("%d:%d", &hours, &minutes);

  return hours * 60 + minutes;
  
}

int findMinDifference(char** timePoints, int timePointsSize) {
  for (int i = 0; i < timePointsSize - 1; i++) {
    int a = timeToMinutes(timePoints[i]);

    for (int j = i + 1; j < timePointsSize; j++) {
      int b = timeToMinutes(timePoints[j]);
    }
  }
}
// @leet end
