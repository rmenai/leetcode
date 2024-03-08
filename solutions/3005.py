from collections import defaultdict
from typing import List


class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        frequencies = defaultdict(int)
        highest = 0
        for num in nums:
            frequencies[num] += 1
            highest = max(highest, frequencies[num])

        return sum([frequency for frequency in frequencies.values() if frequency == highest])


if __name__ == "__main__":
    print(Solution().maxFrequencyElements([1,2,3,4,5]))
