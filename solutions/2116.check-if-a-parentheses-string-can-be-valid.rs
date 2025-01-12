// @leet start
impl Solution {
    pub fn can_be_valid(s: String, locked: String) -> bool {
        if s.len() % 2 == 1 {
            return false;
        }

        let mut left_spaces = 0;
        for (c, locked) in s.chars().zip(locked.chars()) {
            match (c, locked) {
                (_, '0') | ('(', '1') => left_spaces += 1,
                (')', _) => left_spaces -= 1,
                _ => continue,
            }

            if left_spaces < 0 {
                return false;
            }
        }

        let mut right_spaces = 0;
        for (c, locked) in s.chars().rev().zip(locked.chars().rev()) {
            match (c, locked) {
                (_, '0') | (')', '1') => right_spaces += 1,
                ('(', _) => right_spaces -= 1,
                _ => continue,
            }

            if right_spaces < 0 {
                return false;
            }
        }

        true
    }
}
// @leet end

