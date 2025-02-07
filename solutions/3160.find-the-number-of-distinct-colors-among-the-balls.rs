// @leet start
use std::collections::HashMap;
use std::collections::HashSet;

impl Solution {
    pub fn query_results(limit: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut matches = HashMap::new();
        let mut colors = HashMap::new();
        let mut result = Vec::with_capacity(queries.len());

        for query in queries {
            let (x, y) = (query[0] as usize, query[1] as usize);

            if let Some(old) = matches.insert(x, y) {
                if let Some(count) = colors.get_mut(&old) {
                    *count -= 1;
                    if *count == 0 {
                        colors.remove(&old);
                    }
                }
            }

            *colors.entry(y).or_insert(0) += 1;
            result.push(colors.len() as i32);
        }

        result
    }
}
// @leet end

