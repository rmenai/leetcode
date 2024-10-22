#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// @leet start
void fill(struct TreeNode* root, long long int sums[], int i, int *level) {
    if (!root) return;
    sums[i] += root->val;
    if (i+1 > (*level)) *level = i+1;
    fill(root->left, sums, i+1, level);
    fill(root->right, sums, i+1, level);
}

int compare(void* a, void* b) {
    return *(long long*) a < *(long long*) b;
}

long long kthLargestLevelSum(struct TreeNode* root, int k) {
    long long int sums[100000] = {0};
    int i = 0;
    fill(root, sums, 0, &i);
    qsort(sums, i, sizeof(long long), compare);
    return k>i ? -1 : sums[k-1];
}
// @leet end
