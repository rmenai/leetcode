from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        end, middle = head, head
        while end and end.next:
            end = end.next.next
            middle = middle.next

        # Reverse second half
        curr = middle
        prev = None
        while curr:
            upcoming = curr.next
            curr.next = prev
            prev = curr
            curr = upcoming

        start = head
        end = prev
        while start and end:
            if start.val != end.val:
                return False

            start = start.next
            end = end.next

        return True


if __name__ == "__main__":
    print(Solution().isPalindrome(ListNode(1, ListNode(2, ListNode(2, ListNode(1))))))
