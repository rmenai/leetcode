// @leet start
use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut queue: BinaryHeap<_> = nums.into_iter().map(|x| Reverse(x as i64)).collect();
        let mut count = 0;

        while queue.len() >= 2 && queue.peek().unwrap().0 < k as i64 {
            if let (Some(Reverse(x)), Some(Reverse(y))) = (queue.pop(), queue.pop()) {
                queue.push(Reverse(x * 2 + y));
                count += 1;
            }
        }

        count
    }
}
// @leet end

