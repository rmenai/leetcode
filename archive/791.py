class Solution:
    def customSortString(self, order: str, s: str) -> str:
        occurrences = {letter: 0 for letter in order}
        result = ""
        for letter in s:
            if letter in order:
                occurrences[letter] += 1
            else:
                result += letter

        for letter in order:
            result += letter * occurrences[letter]

        return result


if __name__ == "__main__":
    print(Solution().customSortString("bcafg", "abcd"))
