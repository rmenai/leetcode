from collections import deque
from typing import List


# @leet start
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        length = len(nums)

        nums.sort(reverse=True)

        prefix = [1000 for _ in range(length)]
        prefix[length - 1] = nums[length - 1]

        for i in range(length - 2, -1, -1):
            prefix[i] = prefix[i + 1] + nums[i]

        candidates = deque()
        candidates.append((-1, -target))

        count = 0
        while candidates:
            i, candidate = candidates.popleft()

            if i == length - 1:
                count += 1 if candidate == 0 else 0
                continue

            if abs(candidate) <= prefix[i + 1]:
                candidates.append((i + 1, candidate + nums[i + 1]))
                candidates.append((i + 1, candidate - nums[i + 1]))

        return count


# @leet end
