// @leet start
use std::collections::HashMap;

impl Solution {
    pub fn count_bad_pairs(nums: Vec<i32>) -> i64 {
        let mut counter = HashMap::new();
        let mut good_pairs = 0;

        for (i, &num) in nums.iter().enumerate() {
            let key = num - i as i32;
            if let Some(&count) = counter.get(&key) {
                good_pairs += count;
            }
            *counter.entry(key).or_insert(0) += 1;
        }

        let n = nums.len() as i64;
        let total_pairs = n * (n - 1) / 2;

        total_pairs - good_pairs
    }
}
// @leet end
