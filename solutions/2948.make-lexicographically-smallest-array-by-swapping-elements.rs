// @leet start
use std::collections::BTreeSet;
use std::collections::HashMap;

impl Solution {
    pub fn lexicographically_smallest_array(nums: Vec<i32>, limit: i32) -> Vec<i32> {
        let mut mapping: HashMap<i32, Vec<usize>> = HashMap::new();

        for (i, &num) in nums.iter().enumerate() {
            mapping.entry(num).or_insert_with(Vec::new).push(i);
        }

        let mut sorted = nums.to_vec();
        sorted.push(i32::MAX); // To add an extra window at the end
        sorted.sort();

        let mut smallest = vec![0; nums.len()];
        let mut start = 0;

        for (i, window) in sorted.windows(2).enumerate() {
            if window[0] + limit < window[1] {
                let indices: BTreeSet<_> = sorted[start..=i]
                    .iter()
                    .filter_map(|&num| mapping.get(&num).map(|positions| positions.iter()))
                    .flatten()
                    .collect();

                for (&j, num) in indices.iter().zip(sorted[start..=i].iter()) {
                    smallest[*j] = *num;
                }

                start = i + 1;
            }
        }

        smallest
    }
}
// @leet end

