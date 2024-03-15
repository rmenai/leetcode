from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zeros = 0
        total = 1
        for num in nums:
            if num == 0:
                zeros += 1
            else:
                total *= num

        if zeros > 1:
            return [0] * len(nums)

        if zeros == 1:
            return [0 if num != 0 else total for num in nums]

        return [int(total * (num ** -1)) for num in nums]


if __name__ == "__main__":
    print(Solution().productExceptSelf([1, 2, 3, 4]))
