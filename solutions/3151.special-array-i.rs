// @leet start
impl Solution {
    pub fn is_array_special(nums: Vec<i32>) -> bool {
        for window in nums.windows(2) {
            if (window[0] + window[1]) % 2 == 0 {
                return false;
            }
        }

        true
    }
}
// @leet end

