// @leet start
impl Solution {
    pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
        let characters: Vec<char> = blocks.chars().collect();

        fn count_white(w: &[char]) -> i32 {
            w.iter().filter(|c| **c == 'W').count() as i32
        }

        characters
            .windows(k as usize)
            .min_by(|w, v| count_white(w).cmp(&count_white(v)))
            .unwrap_or(&characters)
            .iter()
            .filter(|c| **c == 'W')
            .count() as i32
    }
}
// @leet end

