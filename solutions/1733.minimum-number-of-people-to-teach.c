#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// @leet start
int min(int a, int b) { return a < b ? a : b; }

int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize, int** friendships,
                     int friendshipsSize, int* friendshipsColSize) {
  int m = languagesSize;

  bool knows_lang[m + 1][n + 1];
  memset(knows_lang, false, sizeof(knows_lang));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < languagesColSize[i]; j++) {
      knows_lang[i + 1][languages[i][j]] = true;
    }
  }

  bool needs_help[m + 1];
  memset(needs_help, false, sizeof(needs_help));
  for (int i = 0; i < friendshipsSize; i++) {
    int u = friendships[i][0];
    int v = friendships[i][1];

    bool can_communicate = false;
    for (int lang = 1; lang <= n; lang++) {
      if (knows_lang[u][lang] && knows_lang[v][lang]) {
        can_communicate = true;
        break;
      }
    }

    if (!can_communicate) {
      needs_help[u] = true;
      needs_help[v] = true;
    }
  }

  int min_teachings = m;

  for (int lang = 1; lang <= n; lang++) {  // Try teaching this language
    int current_teach_count = 0;
    for (int user = 1; user <= m; user++) {
      if (needs_help[user] && !knows_lang[user][lang]) {
        current_teach_count++;
      }
    }
    min_teachings = min(min_teachings, current_teach_count);
  }

  return min_teachings;
}
// @leet end
