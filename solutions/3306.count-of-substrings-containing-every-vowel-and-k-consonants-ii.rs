// @leet start
use std::collections::HashSet;

impl Solution {
    pub fn count_of_substrings(word: String, k: i32) -> i64 {
        let vowels = HashSet::from(['a', 'e', 'i', 'o', 'u']);
        let n = word.len();

        fn indice(c: char) -> usize {
            match c {
                'a' => 0,
                'e' => 1,
                'i' => 2,
                'o' => 3,
                'u' => 4,
                _ => 9,
            }
        }

        let letters: Vec<usize> = word
            .chars()
            .enumerate()
            .filter(|(_, c)| !vowels.contains(c))
            .map(|(i, _)| i)
            .collect();

        let mut prefix_vowel: Vec<Vec<i32>> = vec![];

        for c in word.chars() {
            let mut count = prefix_vowel.last().unwrap_or(&vec![0, 0, 0, 0, 0]).to_vec();

            if vowels.contains(&c) {
                count[indice(c)] += 1;
            }

            prefix_vowel.push(count);
        }

        let mut count = 0;

        for i in 0..=(letters.len() - k as usize) {
            let j = i + k as usize - 1;

            let start = letters.get(i - 1).unwrap_or(&0);
            let end = letters.get(j + 1).unwrap_or(&n);

            let from_start = prefix_vowel
                .get(start - 1)
                .unwrap_or(&vec![0, 0, 0, 0, 0])
                .to_vec();

            let from_end = prefix_vowel.get(end - 1).unwrap();

            let mut verified = true;

            for (b, e) in from_start.iter().zip(from_end) {
                if e - b < 1 {
                    verified = false;
                    break;
                }
            }

            if verified {
                count += 1;
            }
        }

        count
    }
}
// @leet end

