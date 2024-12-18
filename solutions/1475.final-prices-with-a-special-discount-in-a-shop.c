#include <stdbool.h>
#include <stdlib.h>

// @leet start
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
  int* newPrices = (int*)malloc(pricesSize * sizeof(int));
  for (int i = 0; i < pricesSize; i++) {
    bool discounted = false;
    for (int j = i + 1; j < pricesSize; j++) {
      if (prices[j] <= prices[i]) {
        newPrices[i] = prices[i] - prices[j];
        discounted = true;
        break;
      }
    }

    if (!discounted) {
      newPrices[i] = prices[i];
    }
  }

  *returnSize = pricesSize;
  return newPrices;
}
// @leet end
