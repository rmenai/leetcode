// @leet start
impl Solution {
    pub fn min_max_difference(num: i32) -> i32 {
        let digits = num.to_string();

        let digit_to_maximize = digits
            .chars()
            .find(|&c| c != '9')
            .unwrap_or_else(|| digits.chars().next().unwrap());

        let digit_to_minimize = digits.chars().next().unwrap();

        let max_num_str = digits.replace(digit_to_maximize, "9");
        let min_num_str = digits.replace(digit_to_minimize, "0");

        let max_val = max_num_str.parse::<i32>().unwrap();
        let min_val = min_num_str.parse::<i32>().unwrap();

        max_val - min_val
    }
}
// @leet end
