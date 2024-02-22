from typing import List
from collections import defaultdict


class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        judges = defaultdict(int)
        trustees = set()
        for person, judge in trust:
            judges[judge] += 1
            trustees.add(person)

        for judge, num in judges.items():
            if num == n - 1 and judge not in trustees:
                return judge

        return n if len(trustees) == 0 and n == 1 else -1


if __name__ == "__main__":
    print(Solution().findJudge(1, []))
