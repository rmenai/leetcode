// @leet start
use std::collections::VecDeque;

impl Solution {
    pub fn check_if_prerequisite(
        num_courses: i32,
        prerequisites: Vec<Vec<i32>>,
        queries: Vec<Vec<i32>>,
    ) -> Vec<bool> {
        let mut next_courses = vec![vec![]; num_courses as usize];
        let mut in_degree = vec![0; num_courses as usize];

        for preq in prerequisites {
            let (a, b) = (preq[0], preq[1]);

            next_courses[a as usize].push(b as usize);
            in_degree[b as usize] += 1;
        }

        let mut queue: VecDeque<usize> = VecDeque::new();

        for (course, &degree) in in_degree.iter().enumerate() {
            if degree == 0 {
                queue.push_front(course);
            }
        }

        let mut topo_sorted = vec![];

        while let Some(course) = queue.pop_back() {
            topo_sorted.push(course);

            for &next in &next_courses[course] {
                in_degree[next] -= 1;

                if in_degree[next] == 0 {
                    queue.push_front(next);
                }
            }
        }

        let mut reachable = vec![vec![false; num_courses as usize]; num_courses as usize];

        for &course in &topo_sorted {
            for &next in &next_courses[course] {
                reachable[course][next] = true;

                for i in 0..num_courses as usize {
                    if reachable[i][course] {
                        reachable[i][next] = true;
                    }
                }
            }
        }

        queries
            .into_iter()
            .map(|query| reachable[query[0] as usize][query[1] as usize])
            .collect()
    }
}
// @leet end

