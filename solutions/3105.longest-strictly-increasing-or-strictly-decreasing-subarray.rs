// @leet start
use std::cmp::Ordering::{Equal, Greater, Less};

impl Solution {
    pub fn longest_monotonic_subarray(nums: Vec<i32>) -> i32 {
        let (mut inc, mut dec, mut cinc, mut cdec) = (1, 1, 1, 1);

        for window in nums.windows(2) {
            let (a, b) = (window[0], window[1]);

            match a.cmp(&b) {
                Less => {
                    cinc += 1;
                    cdec = 1;
                }
                Greater => {
                    cdec += 1;
                    cinc = 1;
                }
                Equal => {
                    cinc = 1;
                    cdec = 1;
                }
            }

            inc = inc.max(cinc);
            dec = dec.max(cdec);
        }

        usize::max(inc, dec) as i32
    }
}
// @leet end

