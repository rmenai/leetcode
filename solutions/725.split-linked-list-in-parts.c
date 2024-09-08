// @leet start
struct ListNode {
  int val;
  struct ListNode *next;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode **splitListToParts(struct ListNode *head, int k,
                                   int *returnSize) {

  struct ListNode **result = malloc(k * sizeof(struct ListNode));
  *returnSize = k;

  return result;
}
// @leet end
