// @leet start
impl Solution {
    pub fn merge_arrays(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut ids = vec![0; 1001];

        for num in nums1 {
            ids[num[0] as usize] += num[1];
        }

        for num in nums2 {
            ids[num[0] as usize] += num[1];
        }

        ids.iter()
            .enumerate()
            .filter(|(_, v)| **v != 0)
            .map(|(i, &v)| vec![i as i32, v])
            .collect()
    }
}
// @leet end

