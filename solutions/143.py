from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # Find middle node
        curr, middle = head, head
        while curr and curr.next:
            curr = curr.next.next
            middle = middle.next

        # Reverse second half of list
        curr = middle
        past = None
        while curr:
            upcoming = curr.next
            curr.next = past
            past = curr
            curr = upcoming

        # Merge the two parts
        curr1 = head
        curr2 = past
        while curr2:
            upcoming = curr1.next
            curr1.next = curr2
            curr1 = curr2
            curr2 = upcoming

        curr1.next = None


if __name__ == "__main__":
    a = ListNode(1, ListNode(2, ListNode(3, ListNode(4, None))))
    Solution().reorderList(a)

    while a:
        print(a.val)
        a = a.next
