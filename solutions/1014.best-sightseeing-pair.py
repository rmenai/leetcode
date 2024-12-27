from typing import List


# @leet start
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        keep = [(0, values[0])]
        count = 0
        j = 1
        for i in range(1, len(values)):
            if values[i] != values[i - 1]:
                count = 0

            if count < 2:
                keep.append((j, values[i]))
                j += 1

            count += 1

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

