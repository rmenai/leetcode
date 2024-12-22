# @leet start
from sortedcontainers import SortedList
import heapq


class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        ordered_set = SortedList(range(len(heights)))

        h = [(heights[i], i) for i in range(len(heights))]
        heapq.heapify(h)

        q = [(queries[i], i) for i in range(len(queries))]
        q.sort(key=lambda a: max(heights[a[0][0]], heights[a[0][1]]))

        result = [-1 for _ in range(len(queries))]

        for query, index in q:
            i, j = query
            m = max(i, j, key=lambda a: heights[a])
            while h[0][0] < heights[m]:
                _, k = heapq.heappop(h)
                ordered_set.remove(k)

            # return list(ordered_set)
            pos = ordered_set.bisect_right(m)
            if pos < len(ordered_set):
                result[index] = ordered_set[pos]

        return result


# @leet end
