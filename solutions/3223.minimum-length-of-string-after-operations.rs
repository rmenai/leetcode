// @leet start
impl Solution {
    pub fn minimum_length(s: String) -> i32 {
        let mut letters = [0; 26];

        for c in s.bytes() {
            letters[(c - b'a') as usize] += 1;
        }

        let mut min_length = 0;
        for count in letters.iter().filter(|&c| *c != 0) {
            min_length += if count % 2 == 0 { 2 } else { 1 }
        }

        min_length
    }
}
// @leet end

