# @leet start
class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        dp = [1] + [0] * high
        limit = 10**9 + 7

        for i in range(1, high + 1):
            if i >= zero:
                dp[i] += dp[i - zero]

            if i >= one:
                dp[i] += dp[i - one]

            dp[i] %= limit

        return sum(dp[low : high + 1]) % limit


# @leet end

