// @leet start
int largestCombination(int* candidates, int candidatesSize) {
  const int INT_SIZE = 8 * sizeof(int);

  int bitsFrequency[INT_SIZE];
  for (int i = 0; i < INT_SIZE; i++) {
    bitsFrequency[i] = 0;
  }

  for (int i = 0; i < candidatesSize; i++) {
    int candidate = candidates[i];
    int bitIndex = 0;
    while (candidate > 0) {
      bitsFrequency[bitIndex++] += candidate & 1;
      candidate >>= 1;
    }
  }

  int max = bitsFrequency[0];
  for (int i = 1; i < INT_SIZE; i++) {
    if (bitsFrequency[i] > max) {
      max = bitsFrequency[i];
    }
  }

  return max;
}
// @leet end
