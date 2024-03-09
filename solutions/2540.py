from typing import List


class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        nums = list(sorted(list(set(nums1)) + list(set(nums2))))
        past = nums[0]
        for num in nums[1:]:
            if num == past:
                return num
            past = num
        return -1


if __name__ == "__main__":
    print(Solution().getCommon([1, 1, 2], [2, 4]))
