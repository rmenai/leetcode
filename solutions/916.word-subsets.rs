// @leet start
impl Solution {
    pub fn get_count(word: &str) -> Vec<i32> {
        let mut letters = vec![0; 26];
        for c in word.chars() {
            letters[(c as usize) - ('a' as usize)] += 1;
        }

        letters
    }

    pub fn word_subsets(words1: Vec<String>, words2: Vec<String>) -> Vec<String> {
        let mut union = [0; 26];
        for word in words2 {
            let letters = Solution::get_count(&word);
            for (letter, &new_count) in letters.iter().enumerate() {
                union[letter] = i32::max(union[letter], new_count);
            }
        }

        let mut universal: Vec<String> = vec![];
        'words: for word in words1 {
            let letters = Solution::get_count(&word);
            for (letter, &required_count) in union.iter().enumerate() {
                if letters[letter] < required_count {
                    continue 'words;
                }
            }

            universal.push(word);
        }

        universal
    }
}
// @leet end

