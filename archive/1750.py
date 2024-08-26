class Solution:
    def minimumLength(self, s: str) -> int:
        start, end = 0, len(s) - 1
        length = len(s)

        while start < end:
            prefix = s[start]
            while start < len(s) and s[start] == prefix:
                start += 1

            suffix = s[end]
            while end > 0 and s[end] == suffix:
                end -= 1

            if prefix == suffix:
                length = end - start + 1
            else:
                break

        return max(length, 0)


if __name__ == "__main__":
    print(Solution().minimumLength(""))
