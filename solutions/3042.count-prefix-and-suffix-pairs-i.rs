// @leet start
impl Solution {
    pub fn count_prefix_suffix_pairs(words: Vec<String>) -> i32 {
        let mut count = 0;
        for i in 0..(words.len() - 1) {
            for j in (i + 1)..words.len() {
                if words[j].starts_with(&words[i]) && words[j].ends_with(&words[i]) {
                    count += 1;
                }
            }
        }

        count
    }
}
// @leet end

