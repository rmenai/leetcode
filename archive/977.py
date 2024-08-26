from typing import List


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        result = []
        negatives = []
        past = 0
        for num in nums:
            if num < 0:
                negatives.insert(0, num)
                continue

            while negatives and past <= abs(negatives[0]) <= num:
                result.append(negatives[0] ** 2)
                past = abs(negatives.pop(0))

            result.append(num ** 2)
            past = num

        return result + [num ** 2 for num in negatives]


if __name__ == "__main__":
    print(Solution().sortedSquares([-2, 0]))
