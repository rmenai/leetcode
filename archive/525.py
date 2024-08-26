from typing import List


class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        prefix = {}
        sum_val, max_len = 0, 0
        for i, num in enumerate(nums):
            sum_val += 1 if num == 1 else -1
            if sum_val == 0:
                max_len = i + 1
            elif sum_val in prefix:
                max_len = max(max_len, i - prefix[sum_val])
            else:
                prefix[sum_val] = i
        return max_len


if __name__ == "__main__":
    print(Solution().findMaxLength([0, 0, 1, 0, 0, 0, 1, 1]))
