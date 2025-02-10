// @leet start
impl Solution {
    pub fn clear_digits(s: String) -> String {
        let mut stack: Vec<char> = vec![];

        for c in s.chars() {
            if let Some(head) = stack.pop() {
                if head.is_digit(10) && c.is_alphabetic() || head.is_alphabetic() && c.is_digit(10)
                {
                    continue;
                }

                stack.push(head);
            }

            stack.push(c);
        }

        stack.iter().collect()
    }
}
// @leet end

