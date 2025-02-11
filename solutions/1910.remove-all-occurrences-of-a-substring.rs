// @leet start
impl Solution {
    pub fn remove_occurrences(s: String, part: String) -> String {
        let mut result = String::with_capacity(s.len());

        for c in s.chars() {
            result.push(c);
            if result.ends_with(&part) {
                for _ in 0..part.len() {
                    result.pop();
                }
            }
        }

        result
    }
}
// @leet end
