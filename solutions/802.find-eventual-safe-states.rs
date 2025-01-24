// @leet start
use std::collections::VecDeque;

impl Solution {
    pub fn eventual_safe_nodes(graph: Vec<Vec<i32>>) -> Vec<i32> {
        let n = graph.len();
        let mut indegree = graph.iter().map(|n| n.len()).collect();
        let mut adj = vec![vec![]; n];

        for (i, nodes) in graph.iter().enumerate() {
            for &node in nodes {
                adj[node as usize].push(i);
            }
        }

        let mut queue: VecDeque<_> = (0..n).filter(|&i| indegree[i] == 0).collect();
        let mut safe_nodes = vec![];

        while let Some(i) = queue.pop_front() {
            safe_nodes.push(i as i32);

            for &j in adj[i].iter() {
                indegree[j] -= 1;
                if indegree[j] == 0 {
                    queue.push_back(j);
                }
            }
        }

        safe_nodes.sort();
        safe_nodes
    }
}
// @leet end

