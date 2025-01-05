// @leet start
impl Solution {
    pub fn shift_char(c: char, shift: i32) -> char {
        const BASE: u8 = b'a';

        let offset = c as u8 - BASE;
        let shifted = ((offset as i32 + shift).rem_euclid(26)) as u8;

        (BASE + shifted) as char
    }

    pub fn shifting_letters(s: String, shifts: Vec<Vec<i32>>) -> String {
        let mut acc = vec![0; s.len()];
        let mut shifted_s = String::new();

        for shift in shifts {
            let start = shift[0] as usize;
            let end = shift[1] as usize;
            let delta = if shift[2] == 0 { -1 } else { 1 };

            acc[start] += delta;
            if let Some(value) = acc.get_mut(end + 1) {
                *value -= delta;
            }
        }

        let mut shift: i32 = 0;
        for (i, c) in s.chars().enumerate() {
            shift += acc[i];
            shifted_s.push(Solution::shift_char(c, shift));
        }

        shifted_s
    }
}

// @leet end



