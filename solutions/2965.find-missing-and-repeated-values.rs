// @leet start
impl Solution {
    pub fn find_missing_and_repeated_values(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let n = grid.len();

        let expected_sum = ((n * n) * (n * n + 1) / 2) as i32;
        let expected_square = (((n * n) * (n * n + 1) * (2 * n * n + 1)) / 6) as i32;

        let mut actual_sum = 0;
        let mut actual_square = 0;

        for i in 0..n {
            for j in 0..n {
                actual_sum += grid[i][j];
                actual_square += grid[i][j] * grid[i][j];
            }
        }

        let c1 = expected_sum - actual_sum;
        let c2 = expected_square - actual_square;
        let c3 = c2 / c1;

        let a = (c3 - c1) / 2;
        let b = (c1 + c3) / 2;

        vec![a, b]
    }
}
// @leet end
