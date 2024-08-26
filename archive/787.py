# Couldn't solve by my own :(

from collections import defaultdict
from typing import List


class Solution:
    def findCheapest(self, n: int, graph: dict[int: set[tuple]], src: int, dst: int, k: int) -> int:
        if src == dst:
            return 0

        if k == 0:
            flights = graph.get(src, [])
            for flight in flights:
                if flight[0] == dst:
                    return flight[1]
            return -1

        prices = []
        for flight in graph[src]:
            price = self.findCheapest(n - 1, graph, flight[0], dst, k - 1)
            if price != -1:
                prices.append(flight[1] + price)

        if not prices:
            return -1

        return min(prices)

    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = defaultdict(set)
        for flight in flights:
            graph[flight[0]].add((flight[1], flight[2]))

        return self.findCheapest(n, graph, src, dst, k)


if __name__ == "__main__":
    print(Solution().findCheapestPrice(4, [[1, 2, 100], [1, 5, 100], [5, 2, 100]], 1, 4, 1000))
