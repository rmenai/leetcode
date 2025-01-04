// @leet start
impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        let mut num = num;

        while num > 9 {
            num = num
                .to_string()
                .chars()
                .map(|d| d.to_digit(10).unwrap() as i32)
                .sum();
        }

        num
    }
}
// @leet end

