#include <stdbool.h>
#include <stdlib.h>

// @leet start
int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
  int* values = (int*)malloc(basketsSize * sizeof(int));
  for (int i = 0; i < basketsSize; i++) {
    values[i] = -1;
  }

  int left = 0;
  for (int i = 0; i < fruitsSize; i++) {
    bool placed = false;

    for (int j = 0; j < basketsSize; j++) {
      if (fruits[i] <= baskets[j] && values[j] == -1) {
        values[j] = i;
        placed = true;
        break;
      }
    }

    if (!placed) {
      left += 1;
    };
  }

  return left;
}
// @leet end
