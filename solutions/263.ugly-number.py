# @leet start
class Solution:
    def isUgly(self, n: int) -> bool:
        if n == 0:
            return False

        for digit in {2, 3, 5}:
            while n % digit == 0:
                n //= digit

        return n == 1


# @leet end

