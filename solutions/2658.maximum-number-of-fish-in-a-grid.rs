// @leet start
impl Solution {
    pub fn find_max_fish(grid: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (grid.len(), grid[0].len());
        let mut visited = [[false; 10]; 10];

        fn visit(grid: &[Vec<i32>], visited: &mut [[bool; 10]; 10], i: usize, j: usize) -> i32 {
            visited[i][j] = true;

            if grid[i][j] == 0 {
                return 0;
            }

            let mut fish = grid[i][j];
            let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];

            for (di, dj) in directions {
                let (ni, nj) = (i as i32 + di, j as i32 + dj);

                if 0 <= ni && 0 <= nj && ni < grid.len() as i32 && nj < grid[0].len() as i32 {
                    let (ni, nj) = (ni as usize, nj as usize);

                    if grid[ni][nj] > 0 && !visited[ni][nj] {
                        fish += visit(grid, visited, ni, nj);
                    }
                }
            }

            fish
        }

        let mut max = i32::MIN;
        for i in 0..m {
            for j in 0..n {
                if !visited[i][j] {
                    let fish = visit(&grid, &mut visited, i, j);
                    max = i32::max(max, fish);
                }
            }
        }

        max
    }
}
// @leet end

