#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

// @leet start
#define SIZE 16384

struct TreeNode* pop(struct TreeNode** stack, int* top) {
  if (*top != -1) {
    return stack[(*top)--];
  }

  return NULL;
}

void push(struct TreeNode** stack, int* top, struct TreeNode* val) { stack[++(*top)] = val; }

struct TreeNode** create() { return (struct TreeNode**)malloc(SIZE * sizeof(struct TreeNode*)); }

bool isEmpty(struct TreeNode** stack, int* top) { return (*top) == -1; }

struct TreeNode* reverseOddLevels(struct TreeNode* root) {
  struct TreeNode** stack = create();
  int top = -1;

  push(stack, &top, root);

  int level = 0;
  int current = 1;
  int left = current;

  while (!isEmpty(stack, &top)) {
    struct TreeNode* node = pop(stack, &top);
    left--;

    if (node != NULL) {
      push(stack, &top, node->left);
      push(stack, &top, node->right);

      node->val = level;
      // if (level % 2 == 1) {
      //   node->val = 0;
      // }

      if (left == 0) {
        current *= 2;
        left = current;
        level++;
      }
    }
  }

  return root;
}
// @leet end
