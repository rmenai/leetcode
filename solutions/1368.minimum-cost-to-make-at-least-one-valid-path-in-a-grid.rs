// @leet start
use std::cmp::Reverse;
use std::collections::BinaryHeap;
use std::collections::VecDeque;

impl Solution {
    pub fn min_cost(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let target = (m - 1, n - 1);

        // 1, 2, 3, 4
        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];

        // Stores (cost, (row, col))
        let mut queue = VecDeque::new();
        queue.push_back((0, 0));

        let mut costs = vec![vec![i32::MAX; n]; m];
        costs[0][0] = 0;

        while let Some((y, x)) = queue.pop_back() {
            let cost = costs[y][x];

            if (y, x) == target {
                return cost;
            }

            // 1 is right, 2 is left, 3 is lower, 4 is upper
            let free_direction = directions[grid[y][x] as usize - 1];

            for (dy, dx) in directions {
                let ny = y as isize + dy;
                let nx = x as isize + dx;

                if ny >= 0 && nx >= 0 && ny < m as isize && nx < n as isize {
                    let ny = ny as usize;
                    let nx = nx as usize;

                    let new_cost = cost + if (dy, dx) == free_direction { 0 } else { 1 };

                    if new_cost < costs[ny][nx] {
                        costs[ny][nx] = new_cost;

                        if new_cost == cost {
                            queue.push_back((ny, nx));
                        } else {
                            queue.push_front((ny, nx));
                        }
                    }
                }
            }
        }

        -1
    }
}
// @leet end

