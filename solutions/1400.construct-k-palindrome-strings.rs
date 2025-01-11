// @leet start
impl Solution {
    pub fn can_construct(s: String, k: i32) -> bool {
        let mut letters = [0; 26];

        for c in s.bytes() {
            letters[(c - b'a') as usize] += 1;
        }

        let mut possible_words = 0;
        let mut required_words = 0;

        for occurence in letters.iter() {
            required_words += occurence % 2;
            possible_words += occurence - occurence % 2;
        }

        if k >= required_words && (k - required_words) <= possible_words {
            return true;
        }

        false
    }
}
// @leet end
