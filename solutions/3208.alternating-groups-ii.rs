// @leet start
impl Solution {
    pub fn number_of_alternating_groups(colors: Vec<i32>, k: i32) -> i32 {
        let mut wrap = colors.clone();
        wrap.extend(&colors[..(k as usize - 1)]);

        let mut result = 0;
        let mut count = 0;

        for i in 1..(wrap.len() - 1) {
            if wrap[i - 1] != wrap[i] && wrap[i] != wrap[i + 1] {
                count += 1;
            } else {
                count = 0;
            }

            if count >= k - 2 {
                result += 1;
            }
        }

        result
    }
}
// @leet end

