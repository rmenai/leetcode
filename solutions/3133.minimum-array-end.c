// @leet start
long long minEnd(int n, int x) {
  long long num = x;
  for (int _ = 1; _ < n; _++) {
    num = (num + 1) | x;
  }

  return num;
}
// @leet end
