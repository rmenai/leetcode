# @leet start
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_chars = set(s)
        t_chars = set(t)

        is_anagram = True
        for c in s_chars:
            if c not in t_chars:
                is_anagram = False

        return is_anagram


# @leet end

