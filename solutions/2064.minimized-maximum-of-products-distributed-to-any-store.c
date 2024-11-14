#include <stdbool.h>

// @leet start
bool canDistribute(int n, int *quantities, int quantitiesSize, int x) {
  int j = 0;

  int remaining = quantities[j];
  for (int i = 0; i < n; i++) {
    if (remaining <= x) {
      j += 1;
      if (j == quantitiesSize) {
        return true;
      } else {
        remaining = quantities[j];
      }
    }
    else {
      remaining -= x;
    }
  }

  return false;
}

int max(int *a, int size) {
  int currentMax = a[0];
  for (int i = 1; i < size; i++) {
    if (a[i] > currentMax) {
      currentMax = a[i];
    }
  }

  return currentMax;
}

int minimizedMaximum(int n, int* quantities, int quantitiesSize) {
  int left = 0;
  int right = max(quantities, quantitiesSize);

  while (left < right) {
    int mid = (left + right) / 2;
    if (canDistribute(n, quantities, quantitiesSize, mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return left;
}
// @leet end
