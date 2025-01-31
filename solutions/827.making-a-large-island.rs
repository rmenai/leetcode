// @leet start
use std::collections::HashSet;
use std::collections::VecDeque;

impl Solution {
    pub fn largest_island(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();

        fn explore(
            grid: &[Vec<i32>],
            groups: &mut [Vec<usize>],
            gi: usize,
            ii: usize,
            ij: usize,
        ) -> i32 {
            let m = grid.len();
            let n = grid[0].len();

            let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];
            let mut queue = VecDeque::new();

            queue.push_back((ii, ij));
            groups[ii][ij] = gi;

            let mut area = 0;

            while let Some((i, j)) = queue.pop_front() {
                area += 1;

                for (di, dj) in &directions {
                    let (ni, nj) = (i as i32 + di, j as i32 + dj);
                    if ni >= 0 && nj >= 0 && ni < m as i32 && nj < n as i32 {
                        let (ni, nj) = (ni as usize, nj as usize);

                        if grid[ni][nj] == 1 && groups[ni][nj] == 0 {
                            queue.push_back((ni, nj));
                            groups[ni][nj] = gi;
                        }
                    }
                }
            }

            area
        }

        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];

        let mut assigned = vec![vec![0; n]; m];
        let mut land = vec![0];
        let mut group_index = 1;

        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 && assigned[i][j] == 0 {
                    let area = explore(&grid, &mut assigned, group_index, i, j);
                    land.push(area as usize);
                    group_index += 1;
                }
            }
        }

        let mut largest = 0;

        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 {
                    largest = usize::max(largest, land[assigned[i][j]]);
                }

                if grid[i][j] == 0 {
                    let mut area = 1;
                    let mut seen = HashSet::new();

                    for (di, dj) in &directions {
                        let (ni, nj) = (i as i32 + di, j as i32 + dj);
                        if ni >= 0 && nj >= 0 && ni < m as i32 && nj < n as i32 {
                            let (ni, nj) = (ni as usize, nj as usize);
                            let group = assigned[ni][nj];

                            if !seen.contains(&group) {
                                area += land[group];
                                seen.insert(group);
                            }
                        }
                    }

                    largest = usize::max(largest, area);
                }
            }
        }

        largest as i32
    }
}
// @leet end

