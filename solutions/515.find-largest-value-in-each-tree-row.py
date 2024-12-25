from collections import defaultdict, deque
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @leet start
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        row = deque()
        row.append((0, root))

        levels = defaultdict(list)

        while row:
            depth, node = row.popleft()

            if node:
                levels[depth].append(node.val)

                row.append((depth + 1, node.left))
                row.append((depth + 1, node.right))

        return [max(nodes) for nodes in levels.values()]


# @leet end

