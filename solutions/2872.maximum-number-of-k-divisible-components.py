# @leet start
class Solution:
    def _value(self, edges: dict, values: list, k: int, edge: int):
        value = values[edge]
        acc = 0
        for child in edges[edge]:
            v, a = self._value(edges, values, k, child)
            acc += a
            if v % k != 0:
                value += v

        if value % k == 0:
            acc += 1

        return value, acc

    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        graph = {i: [] for i in range(n)}

        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        head = graph[0]

        return self._value(edges, values, k, head)[1]
# @leet end
