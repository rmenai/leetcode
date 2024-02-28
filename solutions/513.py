from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.height = 0
        self.val = 0

    def findLongestHeight(self, node: TreeNode, height):
        if node is not None:
            if height > self.height:
                self.height = height
                self.val = node.val

            self.findLongestHeight(node.left, height + 1)
            self.findLongestHeight(node.right, height + 1)

    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        self.val = root.val
        self.findLongestHeight(root, 0)
        return self.val


if __name__ == "__main__":
    print(Solution().findBottomLeftValue(TreeNode(2, TreeNode(1), TreeNode(3))))
