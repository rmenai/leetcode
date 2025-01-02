from typing import List


# @leet start
class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        VOYELS = {"a", "e", "i", "o", "u"}
        voyels = set()

        for word in words:
            if word[0] in VOYELS and word[-1] in VOYELS:
                voyels.add(word)

        result = []
        for i, j in queries:
            add = 0
            for k in range(i, j + 1):
                if words[k] in voyels:
                    add += 1

            result.append(add)

        return result


# @leet end

