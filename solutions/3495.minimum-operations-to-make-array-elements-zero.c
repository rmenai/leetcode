#include <stdbool.h>
#include <stdlib.h>

// @leet start
long long pow2(int n) {
  int result = 1;

  for (int i = 0; i < n; i++) {
    result *= 2;
  }

  return result;
}

int f(int a) {
  // Calculates the length of the binary representation.
  int count = 0;

  while (a > 0) {
    count++;
    a >>= 1;
  }

  return count;
}

long long minOperations(int **queries, int queriesSize, int *queriesColSize) {
  long long result = 0;

  for (int q = 0; q < queriesSize; q++) {
    int *query = queries[q];
    int l = query[0];
    int r = query[1];

    int f_r = f(r);
    int f_l = f(l);

    int groupLength = f_r - f_l + 1;

    if (groupLength <= 0) {
      return -1;
    }

    long long **groups = (long long **)malloc(groupLength * sizeof(long long *));

    for (int i = 0; i < groupLength; i++) {
      groups[i] = (long long *)malloc(2 * sizeof(long long));

      long long g = pow2(f_l + i - 1);
      long long d = pow2(f_l + i) - 1;

      if (i == 0) {
        g = l;
      }

      if (i == groupLength - 1) {
        d = r;
      }

      groups[i][0] = d - g + 1;
      groups[i][1] = (f_l + i + 1) / 2;
    }

    bool residue = 0;

    for (int i = 0; i < groupLength; i++) {
      result += (groups[i][0] / 2) * groups[i][1];

      if (groups[i][0] % 2 == 1) {
        result += groups[i][1] / 2;

        if (groups[i][1] % 2 == 1) {
          result += (int)residue;
          residue = !residue;
        }
      }

      free(groups[i]);
    }

    result += residue;
    free(groups);
  }

  return result;
}
// @leet end
