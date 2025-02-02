// @leet start
impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let mut drops = 0;

        for window in nums.windows(2) {
            if window[0] > window[1] {
                drops += 1;
            }
        }

        if nums.last().unwrap() > nums.first().unwrap() {
            drops += 1;
        }

        drops <= 1
    }
}
// @leet end

