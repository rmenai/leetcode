from collections import deque
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        nodes = deque([(root, 0)])
        pastNode, pastHeight = None, -1
        while nodes:
            node, height = nodes.pop()
            if node is not None:
                if node.val % 2 == height % 2:
                    return False

                if pastHeight == height:
                    if (node.val - pastNode.val) * (-1)**(height % 2) <= 0:
                        return False

                pastNode = node
                pastHeight = height

                nodes.appendleft((node.left, height + 1))
                nodes.appendleft((node.right, height + 1))

        return True


if __name__ == "__main__":
    print(Solution().isEvenOddTree(TreeNode(3, TreeNode(8, TreeNode(3), TreeNode(5)), TreeNode(2))))
