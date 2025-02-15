// @leet start
impl Solution {
    pub fn punishment_number(n: i32) -> i32 {
        fn can_partition(square: &str, target: u32) -> bool {
            if square.is_empty() && target == 0 {
                return true;
            }

            for i in 0..square.len() {
                let left = &square[..=i];
                let right = &square[i + 1..];
                let value: u32 = left.parse().unwrap();

                if can_partition(right, target - value) {
                    return true;
                }
            }

            false
        }

        let mut punishment_number = 0;

        for i in 1..=(n as u32) {
            if can_partition(&(i * i).to_string(), i) {
                punishment_number += i;
            }
        }

        punishment_number as i32
    }
}
// @leet end
