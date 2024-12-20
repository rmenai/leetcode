from types import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# @leet start


class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        stack = []
        stack.append((root, 0))

        nodes = {}
        while stack:
            node, depth = stack.pop()

            if node is not None:
                if not nodes.get(depth):
                    nodes[depth] = []

                nodes[depth].append(node)

                stack.append((node.left, depth + 1))
                stack.append((node.right, depth + 1))

        for depth, line in nodes.items():
            if depth % 2 == 1:
                values = [node.val for node in line]
                for i in range(len(line)):
                    line[i].val = values[len(line) - i - 1]

        return root


# @leet end
