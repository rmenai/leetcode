#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

// @leet start

int pgcd(int a, int b) {
  if (b == 0) return a;
  return pgcd(b, a % b);
}

struct ListNode *insertGreatestCommonDivisors(struct ListNode *head) {
  if (head->next == NULL) {
    return head;
  }

  struct ListNode *past = head;
  struct ListNode *cur = head->next;

  while (cur != NULL) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = pgcd(past->val, cur->val);

    past->next = node;
    node->next = cur;

    past = cur;
    cur = cur->next;
  }

  return head;
}
// @leet end
