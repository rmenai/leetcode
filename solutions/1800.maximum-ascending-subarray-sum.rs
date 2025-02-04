// @leet start
impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        let mut best = nums[0];
        let mut current = nums[0];
        let mut prev = nums[0];

        for &n in nums.iter().skip(1) {
            current = if n > prev { current + n } else { n };
            best = best.max(current);
            prev = n;
        }

        best
    }
}
// @leet end

