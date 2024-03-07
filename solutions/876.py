from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head.next:
            return head

        cursor, middle = head, head
        while cursor.next.next:
            cursor = cursor.next.next
            middle = middle.next
            if not cursor.next:
                return middle

        return middle.next


if __name__ == "__main__":
    data = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    print(Solution().middleNode(data).val)
