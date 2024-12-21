# @leet start
class Solution:
    def _value(self, graph: dict, values: list, k: int, edge: int):
        value = values[edge]
        acc = 0
        for child in graph[edge]:
            v, a = self._value(graph, values, k, child)
            acc += a
            if v % k != 0:
                value += v

        if value % k == 0:
            acc += 1

        return value, acc

    def propagate(self, graph: list[list[int]], edge: int):
        for child in graph[edge]:
            graph[child].remove(edge)
            self.propagate(graph, child)

    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        graph = [[] for i in range(n)]

        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        head = 0
        self.propagate(graph, head)

        return self._value(graph, values, k, head)[1]
# @leet end
