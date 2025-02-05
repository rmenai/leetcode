// @leet start
impl Solution {
    pub fn are_almost_equal(s1: String, s2: String) -> bool {
        let diffs: Vec<_> = s1.chars().zip(s2.chars()).filter(|(a, b)| a != b).collect();
        diffs.is_empty() || (diffs.len() == 2 && diffs[0] == (diffs[1].1, diffs[1].0))
    }
}
// @leet end

