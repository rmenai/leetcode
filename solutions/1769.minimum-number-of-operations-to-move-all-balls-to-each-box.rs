// @leet start
impl Solution {
    pub fn min_operations(boxes: String) -> Vec<i32> {
        let mut result = vec![0; boxes.len()];
        let mut indices = vec![];

        for (i, c) in boxes.chars().enumerate() {
            if c == '1' {
                indices.push(i);
            }
        }

        for (target, steps) in result.iter_mut().enumerate() {
            for &indice in indices.iter() {
                *steps += i32::abs(indice as i32 - target as i32);
            }
        }

        result
    }
}
// @leet end

