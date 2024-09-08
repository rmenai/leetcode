#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

// @leet start
struct ListNode **splitListToParts(struct ListNode *head, int k, int *returnSize) {
  struct ListNode **heads = calloc(k, sizeof(struct ListNode));
  for (int i = 0; i < k; i++) heads[i] = NULL;

  // Determine linked list size
  int size = 0;
  struct ListNode *cur = head;
  while (cur != NULL) {
    cur = cur->next;
    size++;
  }

  int nodeSize = size / k;
  int leftSize = size - nodeSize * k;

  // Split linked list into k parts
  cur = head;
  for (int i = 0; i < k; i++) {
    int nodeWholeSize = leftSize-- > 0 ? nodeSize + 1 : nodeSize;
    struct ListNode *nodeCur;

    // Initiate first node
    if (nodeWholeSize-- > 0) {
      heads[i] = malloc(sizeof(struct ListNode));
      heads[i]->val = cur->val;
      heads[i]->next = NULL;

      nodeCur = heads[i];
      cur = cur->next;
    }

    // Add other nodes
    for (int j = 0; j < nodeWholeSize; j++) {
      struct ListNode *node = malloc(sizeof(struct ListNode));
      node->val = cur->val;
      node->next = NULL;

      nodeCur->next = node;
      nodeCur = nodeCur->next;
      cur = cur->next;
    }
  }

  *returnSize = k;
  return heads;
}
// @leet end
