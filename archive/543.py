from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def diameter(self, node: Optional[TreeNode], diameters: list):
        if not node:
            return 0

        left = self.diameter(node.left, diameters)
        right = self.diameter(node.right, diameters)

        diameters[0] = max(diameters[0], left + right)
        return max(left, right) + 1

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameters = [0]
        self.diameter(root, diameters)

        return diameters[0]


if __name__ == "__main__":
    print(Solution().diameterOfBinaryTree(TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))))
