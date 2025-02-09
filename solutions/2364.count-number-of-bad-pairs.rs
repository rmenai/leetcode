// @leet start
impl Solution {
    pub fn count_bad_pairs(nums: Vec<i32>) -> i64 {
        let n = nums.len();

        let mut count = 0;
        for i in 0..n - 1 {
            for j in i + 1..n {
                if j as i32 - i as i32 != nums[j] - nums[i] {
                    count += 1;
                }
            }
        }

        count
    }
}
// @leet end
