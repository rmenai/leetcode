#include <stdlib.h>

// @leet start
const char OBSTACLE = '*';
const char STONE = '#';
const char AIR = '.';

char** rotateTheBox(char** box, int boxSize, int* boxColSize, int* returnSize, int** returnColumnSizes) {
  char** reversedBox = (char**)malloc(boxColSize[0] * sizeof(char*));
  *returnSize = boxColSize[0];

  *returnColumnSizes = (int*)malloc(boxColSize[0] * sizeof(int));
  for (int i = 0; i < boxColSize[0]; i++) {
    reversedBox[i] = (char*)malloc(boxSize * sizeof(char));
    (*returnColumnSizes)[i] = boxSize;

    for (int j = 0; j < boxSize; j++) {
      reversedBox[i][j] = AIR;
    }
  }

  for (int i = 0; i < boxSize; i++) {
    int stoneCount = 0;
    int k = boxColSize[i] - 1;
    for (int j = boxColSize[i] - 1; j >= 0; j--) {
      if (box[i][j] == OBSTACLE) {
        for (int _ = 0; _ < stoneCount; _++) {
          reversedBox[k][boxSize - i - 1] = STONE;
          k--;
        }

        k = j;
        reversedBox[k--][boxSize - i - 1] = OBSTACLE;
        stoneCount = 0;
        continue;
      }

      if (box[i][j] == STONE) {
        stoneCount++;
      }
    }

    for (int _ = 0; _ < stoneCount; _++) {
      reversedBox[k][boxSize - i - 1] = STONE;
      k--;
    }
  }

  return reversedBox;
}
// @leet end
