// @leet start
impl Solution {
    pub fn string_matching(words: Vec<String>) -> Vec<String> {
        let mut substrings = vec![];
        for word in &words {
            for other in &words {
                if word != other && other.contains(word) {
                    substrings.push(word.to_string());
                    break;
                }
            }
        }

        substrings
    }
}
// @leet end

