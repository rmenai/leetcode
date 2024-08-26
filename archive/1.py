from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        cache = {}
        for i, num in enumerate(nums):
            rest = target - num
            if rest in cache:
                return [cache[rest], i]
            cache[num] = i
        return []


if __name__ == "__main__":
    print(Solution().twoSum([7, 2, 3], 5))
