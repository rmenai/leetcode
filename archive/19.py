from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        tail, node = None, head
        for _ in range(n):
            node = node.next

        while node:
            tail = head if not tail else tail.next
            node = node.next

        if tail:
            tail.next = tail.next.next
            return head

        return head.next


if __name__ == "__main__":
    data = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    sol = Solution().removeNthFromEnd(data, 1)
    while sol:
        print(sol.val)
        sol = sol.next
