# @leet start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        cache = {}
        for i, num in enumerate(nums):
            rest = target - num
            if rest in cache:
                return [cache[rest], i]

            cache[num] = i


# @leet end

