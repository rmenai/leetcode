from collections import defaultdict
from typing import List


class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        companions = {0, firstPerson}
        timeTable = defaultdict(list)
        for meeting in meetings:
            x, y, time = meeting
            matched = []
            for i, group in enumerate(timeTable[time]):
                if x in group or y in group:
                    matched.append(i)

            if matched:
                mainGroup = timeTable[time][matched[0]]
                mainGroup.update({x, y})
                for i in matched[1:]:
                    group = timeTable[time].pop(i)
                    mainGroup.update(group)
            else:
                timeTable[time].append({x, y})

        times = sorted(timeTable.keys())
        for time in times:
            for group in timeTable[time]:
                for person in group:
                    if person in companions:
                        companions.update(group)
                        break

        return list(companions)


if __name__ == "__main__":
    print(Solution().findAllPeople(6, [[1, 2, 5], [2, 3, 8], [1, 5, 10]], 1))
