class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        result = ""
        sub = ""
        for char in s:
            if char in sub:
                if len(sub) > len(result):
                    result = sub
                sub = sub[sub.find(char) + 1:] + char
            else:
                sub += char

        return max(len(result), len(sub))


if __name__ == "__main__":
    print(Solution().lengthOfLongestSubstring("pwwkew"))
