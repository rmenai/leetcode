// @leet start
impl Solution {
    pub fn grow_palindrome(s: &str, i: i32, j: i32) -> &str {
        let bytes = s.as_bytes();
        let mut gap = 0;

        while (i - gap) >= 0
            && (j + gap) < s.len() as i32
            && bytes[(i - gap) as usize] == bytes[(j + gap) as usize]
        {
            gap += 1;
        }

        let start = i - gap + 1;
        let end = j + gap - 1;

        if start >= 0 && end < s.len() as i32 && start <= end {
            return s.get(start as usize..=end as usize).unwrap_or("");
        }

        ""
    }

    pub fn longest_palindrome(s: String) -> String {
        let mut longest = "";

        for i in 0..s.len() {
            let odd = Solution::grow_palindrome(&s, i as i32, i as i32);
            let even = Solution::grow_palindrome(&s, i as i32, i as i32 + 1);

            if odd.len() > longest.len() {
                longest = odd;
            }

            if even.len() > longest.len() {
                longest = even;
            }
        }

        longest.to_string()
    }
}
// @leet end

