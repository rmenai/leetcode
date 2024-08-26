from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        front = ListNode(0, head)
        start = front

        while start is not None:
            prefix_sum = 0
            end = start.next

            while end is not None:
                prefix_sum += end.val
                if prefix_sum == 0:
                    start.next = end.next
                end = end.next

            start = start.next

        return front.next


if __name__ == "__main__":
    node = Solution().removeZeroSumSublists(ListNode(1, ListNode(2, ListNode(-3, ListNode(3)))))
    while node:
        print(node.val)
        node = node.next
