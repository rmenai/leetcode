// @leet start
use std::collections::HashMap;

impl Solution {
    pub fn num_tile_possibilities(tiles: String) -> i32 {
        let fact = [1, 1, 2, 6, 24, 120, 720, 5040];

        let mut freq = HashMap::new();
        tiles.chars().for_each(|x| *freq.entry(x).or_insert(0) += 1);

        let mut result: i64 = fact[tiles.len()];
        freq.values().for_each(|&x| result /= fact[x as usize]);

        result as i32
    }
}
// @leet end

