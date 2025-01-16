// @leet start
impl Solution {
    pub fn xor_all_nums(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut total_xor = 0;

        for (first, second) in [(&nums1, &nums2), (&nums2, &nums1)] {
            if second.len() % 2 == 1 {
                total_xor ^= first.iter().fold(0, |acc, e| acc ^ e);
            }
        }

        total_xor
    }
}
// @leet end

