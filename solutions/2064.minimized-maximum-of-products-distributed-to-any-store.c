#include <stdlib.h>

int compare(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

// @leet start
int minimizedMaximum(int n, int* quantities, int quantitiesSize) {
  qsort(quantities, quantitiesSize, sizeof(int), compare);


}
// @leet end
