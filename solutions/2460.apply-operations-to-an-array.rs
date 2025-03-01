// @leet start
impl Solution {
    pub fn apply_operations(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;

        for i in 0..nums.len().saturating_sub(1) {
            if nums[i] == nums[i + 1] {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        let (mut nonzero, zeros): (Vec<_>, Vec<_>) = nums.into_iter().partition(|&x| x != 0);
        nonzero.extend(zeros);
        nonzero
    }
}
// @leet end

