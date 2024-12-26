from collections import deque
from typing import List


# @leet start
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        candidates = deque()

        candidates.append(nums[0])
        candidates.append(-nums[0])

        while candidates"


# @leet end

