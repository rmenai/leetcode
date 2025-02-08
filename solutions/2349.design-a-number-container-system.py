# @leet start
class NumberContainers:
    def __init__(self):
        self.nums = []

    def change(self, index: int, number: int) -> None:
        self.nums[index] = number

    def find(self, number: int) -> int:
        try:
            i = self.nums.index(number)
            return i
        except ValueError:
            return -1


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)
# @leet end

