# @leet start
from typing import DefaultDict


class Solution:
    def maximum(self, edges: dict[int, list], n: int = -1, p: int = -1):
        distances = [self.maximum(edges, cell, n) for cell in edges[n] if cell != p]
        return 1 + max(distances, default=-1)

    def minimumDiameterAfterMerge(self, edges1, edges2) -> int:
        graph1 = DefaultDict(list)
        graph2 = DefaultDict(list)

        for a, b in edges1:
            graph1[a].append(b)
            graph1[b].append(a)

        for a, b in edges2:
            graph2[a].append(b)
            graph2[b].append(a)

        paths1 = [self.maximum(graph1, i) for i in range(len(edges1) + 1)]
        paths2 = [self.maximum(graph2, i) for i in range(len(edges2) + 1)]

        return max(min(paths1) + min(paths2) + 1, max(paths1), max(paths2))


# @leet end

