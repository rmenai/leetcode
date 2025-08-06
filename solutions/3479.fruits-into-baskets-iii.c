#include <stdbool.h>
#include <stdlib.h>

// @leet start
int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
  bool* occupied = (bool*)malloc(basketsSize * sizeof(bool));
  for (int i = 0; i < basketsSize; i++) {
    occupied[i] = false;
  }

  int left = fruitsSize;
  int start = 0;

  for (int i = 0; i < fruitsSize; i++) {
    for (int j = start; j < basketsSize; j++) {
      if (fruits[i] <= baskets[j] && !occupied[j]) {
        occupied[j] = true;
        left -= 1;
        break;
      }
    }
  }

  return left;
}
// @leet end
