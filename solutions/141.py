from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        visited = set()
        node = head
        while node:
            if node in visited:
                return True

            visited.add(node)
            node = node.next
        return False


if __name__ == "__main__":
    cycle = ListNode(2, ListNode(0, ListNode(4)))
    cycle.next.next.next = cycle

    data = ListNode(3, cycle)
    print(Solution().hasCycle(data))
