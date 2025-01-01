// @leet start
int maxScore(char* s) {
  int score = s[0] == '0' ? 1 : 0;

  for (int i = 1; s[i] != '\0'; i++) {
    if (s[i] == '1') score++;
  }

  int maxScore = score;
  for (int i = 1; s[i + 1] != '\0'; i++) {
    if (s[i] == '0') score++;
    if (s[i] == '1') score--;
    if (score > maxScore) maxScore = score;
  }

  return maxScore;
}
// @leet end
