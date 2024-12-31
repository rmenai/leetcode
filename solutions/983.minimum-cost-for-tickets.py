from functools import cache
from typing import List


# @leet start
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        isTravelNeeded = set(days)

        @cache
        def dfs(day: int) -> int:
            if day > days[-1]:
                return 0

            if day not in isTravelNeeded:
                return dfs(day + 1)

            return min(
                costs[0] + dfs(day + 1),
                costs[1] + dfs(day + 7),
                costs[2] + dfs(day + 30),
            )

        return dfs(1)


# @leet end

