from typing import List


# @leet start
class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        VOYELS = {"a", "e", "i", "o", "u"}
        prefix_sum = [1 if words[0][0] in VOYELS and words[0][-1] in VOYELS else 0]

        for i in range(1, len(words)):
            prefix_sum.append(prefix_sum[i - 1])
            if words[i][0] in VOYELS and words[i][-1] in VOYELS:
                prefix_sum[i] += 1

        result = []
        for i, j in queries:
            remove = 0 if i - 1 < 0 else prefix_sum[i - 1]
            result.append(prefix_sum[j] - remove)

        return result


# @leet end
