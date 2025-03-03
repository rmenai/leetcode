// @leet start
use std::cmp::Ordering::{Equal, Greater, Less};

impl Solution {
    pub fn pivot_array(nums: Vec<i32>, pivot: i32) -> Vec<i32> {
        let mut left = vec![];
        let mut mid = vec![];
        let mut right = vec![];

        for num in nums {
            match num.cmp(&pivot) {
                Less => left.push(num),
                Greater => right.push(num),
                Equal => mid.push(num),
            }
        }

        left.extend(mid);
        left.extend(right);
        left
    }
}
// @leet end

