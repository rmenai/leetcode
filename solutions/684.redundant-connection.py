from collections import deque
from typing import List


# @leet start
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        reverse = [[] for _ in range(len(edges) + 1)]
        inDegrees = [0] * (len(edges) + 1)

        for a, b in edges:
            inDegrees[a] += 1
            inDegrees[b] += 1

            reverse[b].append(a)

        queue = deque()

        for i, degree in enumerate(inDegrees):
            if degree == 1:
                queue.append(i)

        removed = set()

        while queue:
            i = queue.popleft()
            removed.add(i)

            for j in reverse[i]:
                inDegrees[j] -= 1
                if inDegrees[j] == 1:
                    queue.append(j)

        for a, b in reversed(edges):
            if a not in removed and b not in removed:
                return [a, b]

        return []


# @leet end

