from typing import List


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans = []
        for x in nums:
            x = abs(x)
            if nums[x - 1] < 0:
                ans.append(x)
            nums[x - 1] *= -1
        return ans


if __name__ == "__main__":
    print(Solution().findDuplicates([4, 3, 2, 7, 8, 2, 3, 1]))
