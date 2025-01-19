// @leet start
use std::cmp::Reverse;
use std::collections::BinaryHeap;

pub struct Solution;

impl Solution {
    pub fn trap_rain_water(height_map: Vec<Vec<i32>>) -> i32 {
        let (rows, columns) = (height_map.len(), height_map[0].len());

        if rows < 3 && columns < 3 {
            return 0;
        }

        let mut border = BinaryHeap::new(); // (row, column, height)
        let mut visited: Vec<Vec<bool>> = vec![vec![false; columns]; rows];

        for i in 0..height_map.len() {
            for j in 0..height_map[i].len() {
                if !(i > 0 && i < height_map.len() - 1 && j > 0 && j < height_map[i].len() - 1) {
                    visited[i][j] = true;
                    border.push(Reverse((height_map[i][j], i, j)));
                }
            }
        }

        let dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        let mut water_volume = 0;

        while let Some(Reverse((cur_height, cur_row, cur_col))) = border.pop() {
            for (di, dj) in dirs {
                let ni = (cur_row as i32 + di) as usize;
                let nj = (cur_col as i32 + dj) as usize;

                if ni > 0 && ni < rows - 1 && nj > 0 && nj < columns - 1 && !visited[ni][nj] {
                    water_volume += i32::max(0, cur_height - height_map[ni][nj]);
                    border.push(Reverse((i32::max(cur_height, height_map[ni][nj]), ni, nj)));
                    visited[ni][nj] = true;
                }
            }
        }

        water_volume
    }
}
// @leet end

