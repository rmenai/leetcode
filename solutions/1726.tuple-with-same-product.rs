// @leet start
use std::collections::HashMap;
use std::collections::HashSet;

impl Solution {
    pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
        let mut products: HashMap<i32, HashSet<(i32, i32)>> = HashMap::new();
        let n = nums.len();

        for i in 0..n {
            for j in (i + 1)..n {
                let prod = nums[i] * nums[j];
                products.entry(prod).or_default().insert((nums[i], nums[j]));
            }
        }

        let mut count = 0;
        for pairs in products.values() {
            let k = pairs.len();
            if k > 1 {
                count += (k * (k - 1)) * 4;
            }
        }

        count as i32
    }
}
// @leet end

