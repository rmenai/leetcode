from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow, fast = nums[nums[0]], nums[nums[nums[0]]]
        while slow != fast:
            slow = nums[slow]
            fast = nums[nums[fast]]

        fast = nums[0]
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]

        return fast


if __name__ == "__main__":
    print(Solution().findDuplicate([3,1,3,4,2]))
