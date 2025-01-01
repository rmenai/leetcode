from typing import List


# @leet start
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        leading = 0
        digits[-1] += 1
        for i in range(len(digits) - 1, -1, -1):
            digits[i] += leading
            leading = 0
            if digits[i] > 9:
                leading = digits[i] // 10
                digits[i] %= 10

        if leading > 0:
            digits.insert(0, leading)

        return digits


# @leet end

