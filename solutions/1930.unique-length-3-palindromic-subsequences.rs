// @leet start
use std::collections::HashSet;

impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let letters: HashSet<char> = s.chars().collect();
        let mut count: i32 = 0;

        for letter in letters {
            let mut candidates = HashSet::new();
            let mut seen = HashSet::new();
            for c in s.chars().skip_while(|&c| c != letter).skip(1) {
                match c {
                    char if char == letter => {
                        count += candidates.len() as i32;
                        candidates.clear();

                        if !seen.contains(&letter) {
                            candidates.insert(letter);
                            seen.insert(letter);
                        }
                    }
                    char => {
                        if !seen.contains(&char) {
                            candidates.insert(c);
                            seen.insert(c);
                        }
                    }
                }
            }
        }

        count
    }
}

// @leet end

