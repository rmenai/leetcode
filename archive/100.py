from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p or not q:
            return p == q

        if p.val == q.val:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

        return False


if __name__ == "__main__":
    print(Solution().isSameTree(
        TreeNode(1, TreeNode(2), TreeNode()),
        TreeNode(1, TreeNode(2), TreeNode(1))
    ))
