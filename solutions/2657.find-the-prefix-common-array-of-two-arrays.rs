// @leet start
use std::collections::HashSet;

impl Solution {
    pub fn find_the_prefix_common_array(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        let mut c: Vec<i32> = vec![0; a.len()];

        let mut elements = HashSet::new();
        for (&x, &y) in a.iter().zip(b.iter()) {
            elements.insert(x);
            elements.insert(y);
        }

        for (answer, (x, y)) in c.iter_mut().zip(a.iter().zip(b.iter())).rev() {
            *answer = elements.len() as i32;

            elements.remove(x);
            elements.remove(y);
        }

        c
    }
}
// @leet end

