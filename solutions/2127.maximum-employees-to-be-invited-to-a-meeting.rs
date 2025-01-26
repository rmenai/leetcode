// @leet start
impl Solution {
    pub fn group_nodes(
        edges: &Vec<Vec<usize>>,
        groups: &mut Vec<usize>,
        node: usize,
        id: usize,
    ) -> usize {
        groups[node] = id;
        let mut size = 1;

        for &edge in &edges[node] {
            if groups[edge] == 0 {
                size += Solution::group_nodes(edges, groups, edge, id);
            }
        }

        size
    }

    pub fn find_cycle_size(favorite: &[i32], current: usize, group_size: usize) -> usize {
        let mut current = current;

        // Guaranteed to enter the cycle
        for _ in 0..group_size {
            current = favorite[current] as usize;
        }

        let head = current;
        let mut size = 1;

        while favorite[current] as usize != head {
            current = favorite[current] as usize;
            size += 1;
        }

        size
    }

    pub fn find_linear_size(map: &[Vec<usize>], past: usize, current: usize) -> usize {
        let mut size = 0;

        for &node in &map[current] {
            if node != past {
                size = usize::max(size, Solution::find_linear_size(map, current, node))
            }
        }

        1 + size
    }

    pub fn fix_cycle_size(
        favorite: &[i32],
        map: &[Vec<usize>],
        group_size: &mut [usize],
        group: usize,
        current: usize,
    ) -> usize {
        let mut current = current;

        // Guaranteed to enter the cycle
        for _ in 0..group_size[group] {
            current = favorite[current] as usize;
        }

        let mut size = 0;

        size += Solution::find_linear_size(map, favorite[current] as usize, current);
        size += Solution::find_linear_size(map, current, favorite[current] as usize);

        size
    }

    pub fn maximum_invitations(favorite: Vec<i32>) -> i32 {
        let mut map = vec![vec![]; favorite.len()];

        for (i, &j) in favorite.iter().enumerate() {
            map[i].push(j as usize);
            map[j as usize].push(i);
        }

        // Great groups for each sub-graph
        let mut assigned_group = vec![0; favorite.len()];
        let mut group_size = vec![0];
        let mut current_id = 1;

        // Group sub-graphs and assign group id
        for (node, _) in map.iter().enumerate() {
            if assigned_group[node] == 0 {
                let size = Solution::group_nodes(&map, &mut assigned_group, node, current_id);
                group_size.push(size);
                current_id += 1;
            }
        }

        // Each sub-graph is guaranteed to have a cycle
        let mut group_cycle_size: Vec<usize> = vec![0; group_size.len()];

        for (node, _) in map.iter().enumerate() {
            let group = assigned_group[node];
            if group_cycle_size[group] == 0 {
                let size = Solution::find_cycle_size(&favorite, node, group_size[group]);
                group_cycle_size[group] = size;

                // For cycles of 2, we must fix the real sizes
                if size == 2 {
                    let real_size =
                        Solution::fix_cycle_size(&favorite, &map, &mut group_size, group, node);

                    group_size[group] = real_size;
                }
            }
        }

        let max_cycle_size = *group_cycle_size.iter().max().unwrap();
        let small_groups_sum: usize = group_cycle_size
            .iter()
            .enumerate()
            .filter(|(_, &size)| size == 2)
            .map(|(group, _)| group_size[group])
            .sum();

        usize::max(max_cycle_size, small_groups_sum) as i32
    }
}
// @leet end

