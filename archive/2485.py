class Solution:
    def pivotInteger(self, n: int) -> int:
        s = sum(range(n + 1))
        total = 0
        for num in range(1, n + 1):
            total += num
            if total == s - total + num:
                return num
        return -1


if __name__ == "__main__":
    print(Solution().pivotInteger(8))
