from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l3 = ListNode()
        cur = l3
        past_cur = None

        p = 0
        while l1 or l2 or p:
            if l1 is not None:
                cur.val += l1.val
                l1 = l1.next

            if l2 is not None:
                cur.val += l2.val
                l2 = l2.next

            cur.val += p
            p = cur.val // 10
            if p > 0:
                cur.val -= 10 * p

            cur.next = ListNode()
            past_cur = cur
            cur = cur.next

        if cur.val == 0:
            past_cur.next = None

        return l3


if __name__ == "__main__":
    result = Solution().addTwoNumbers(
        ListNode(2, ListNode(4, ListNode(9))),
        ListNode(5, ListNode(8, ListNode(9)))
    )

    while result is not None:
        print(result.val)
        result = result.next
