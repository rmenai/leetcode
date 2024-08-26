from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[0])

        prev = points[0]
        count = 1
        for i in range(1, len(points)):
            curr_start, curr_end = points[i]
            prev_start, prev_end = prev

            if curr_start > prev_end:
                count += 1
                prev = points[i]
            else:
                prev[0] = max(prev_start, curr_start)
                prev[1] = min(prev_end, curr_end)

        return count


if __name__ == "__main__":
    print(Solution().findMinArrowShots([[1, 2], [3, 4], [5, 6], [7, 8]]))
