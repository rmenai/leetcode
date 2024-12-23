from collections import defaultdict, deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @leet start
class Solution:
    def calculate_swaps(self, nums: list[int]):
        n = len(nums)

        sorted_nums = sorted(enumerate(nums), key=lambda x: x[1])
        visited = [False] * n
        swaps = 0

        for i in range(n):
            if visited[i] or sorted_nums[i][0] == i:
                continue

            j = i
            cycle_size = 0
            while not visited[j]:
                visited[j] = True
                j = sorted_nums[j][0]
                cycle_size += 1

            if cycle_size > 1:
                swaps += cycle_size - 1

        return swaps

    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        stack = deque()
        stack.append((0, root))

        levels = defaultdict(list)

        while stack:
            depth, node = stack.popleft()

            if node == None:
                continue

            levels[depth].append(node.val)

            stack.append((depth + 1, node.left))
            stack.append((depth + 1, node.right))

        total_swaps = 0
        for _, nodes in levels.items():
            total_swaps += self.calculate_swaps(nodes)

        return total_swaps


# @leet end
