import operator
from functools import reduce
from typing import List


class Solution:
    def gcd(self, a: int, b: int):
        return a if b == 0 else self.gcd(b, a % b)

    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        items = set(nums)
        if len(nums) == 1 or len(items) == 1 and nums[0] > 1:
            return True

        multiple = reduce(operator.mul, items)
        for num in items:
            if self.gcd(multiple // num, num) <= 1:
                return False
        return True


if __name__ == "__main__":
    print(Solution().canTraverseAllPairs([4, 3, 12, 8]))
