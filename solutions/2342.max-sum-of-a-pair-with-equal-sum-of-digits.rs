// @leet start
use std::collections::HashMap;

impl Solution {
    pub fn maximum_sum(nums: Vec<i32>) -> i32 {
        let mut sums: HashMap<i32, Vec<i32>> = HashMap::new();
        fn digit_sum(mut num: i32) -> i32 {
            let mut sum = 0;

            while num > 0 {
                sum += num % 10;
                num /= 10;
            }

            sum
        }

        for &num in &nums {
            let digit_sum = digit_sum(num);
            sums.entry(digit_sum).or_default().push(num);
        }

        let mut result = -1;
        for group in sums.values_mut() {
            if group.len() >= 2 {
                group.sort_unstable_by(|a, b| b.cmp(a));
                result = result.max(group[0] + group[1]);
            }
        }

        result
    }
}
// @leet end

