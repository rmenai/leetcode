// @leet start
use std::collections::VecDeque;

impl Solution {
    pub fn magnificent_sets(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let mut adj = vec![vec![]; n as usize + 1];

        for edge in &edges {
            let (a, b) = (edge[0], edge[1]);

            adj[a as usize].push(b as usize);
            adj[b as usize].push(a as usize);
        }

        fn bfs(start: usize, adj: &[Vec<usize>], visited: &mut [bool]) -> (usize, i32) {
            let mut queue = VecDeque::new();
            queue.push_back((start, 0));
            visited[start] = true;

            let mut farthest = (start, 0);

            while let Some((node, dist)) = queue.pop_front() {
                farthest = (node, dist);
                for &neighbor in &adj[node] {
                    if !visited[neighbor] {
                        visited[neighbor] = true;
                        queue.push_back((neighbor, dist + 1));
                    }
                }
            }

            farthest
        }

        fn assign(start: usize, adj: &[Vec<usize>], group: &mut [usize]) -> i32 {
            let mut queue = VecDeque::new();
            queue.push_back(start);
            group[start] = 1;

            let mut max_group = 1;

            while let Some(node) = queue.pop_front() {
                max_group = group[node] as i32;

                for &neighbor in &adj[node] {
                    if group[neighbor] == 0 {
                        group[neighbor] = group[node] + 1;
                        queue.push_back(neighbor);
                    } else if (group[neighbor] as i32 - group[node] as i32).abs() != 1 {
                        return -1;
                    }
                }
            }

            max_group
        }

        let mut visited = vec![false; n as usize + 1];
        let mut group = vec![0; n as usize + 1];

        let mut max_group = 0;

        for node in 1..=n as usize {
            if !visited[node] {
                let (root, _) = bfs(node, &adj, &mut visited);
                let groups = assign(root, &adj, &mut group);

                if groups == -1 {
                    return -1;
                }

                max_group += groups;
            }
        }

        max_group
    }
}
// @leet end

