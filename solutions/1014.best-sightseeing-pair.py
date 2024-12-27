from typing import List


# @leet start
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        counter = []
        last = values[0]
        count = 1
        for i in range(1, len(values)):
            if values[i] != last:
                counter.append((last, count))
                last = values[i]
                count = 1
            else:
                count += 1

        if count > 0:
            counter.append((values[-1], count))

        keep = []
        j = 0
        for val, count in counter:
            if count < 4:
                for _ in range(count):
                    keep.append((j, val))
                    j += 1
            else:
                for _ in range(2):
                    keep.append((j, val))
                    j += 1

                j += count - 4

                for _ in range(2):
                    keep.append((j, val))
                    j += 1

        keep.sort(key=lambda a: a[1], reverse=True)

        best = float("-inf")
        for y in range(len(keep) - 1):
            i, first = keep[y]
            for x in range(y + 1, len(keep)):
                j, second = keep[x]

                potential = first + second
                if potential <= best:
                    break

                score = potential - abs(i - j)
                best = max(best, score)

        return int(best)


# @leet end
