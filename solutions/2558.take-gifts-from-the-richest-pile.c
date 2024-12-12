#include <stdlib.h>
#include <math.h>

// @leet start
int compare(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

long long pickGifts(int* gifts, int giftsSize, int k) {
  qsort(gifts, giftsSize, sizeof(int), compare);

  for (int _ = 0; _ < k; _++) {
    int max = gifts[giftsSize - 1];
    gifts[giftsSize - 1] = sqrt(max);
    qsort(gifts, giftsSize, sizeof(int), compare);
  }

  long long sum = 0;
  for (int i = 0; i < giftsSize; i++) {
    sum += gifts[i];
  }

  return sum;
}
// @leet end
