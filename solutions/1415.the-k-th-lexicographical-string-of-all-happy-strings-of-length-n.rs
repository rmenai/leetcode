// @leet start
impl Solution {
    pub fn get_happy_string(n: i32, k: i32) -> String {
        let chars = ['a', 'b', 'c'];
        let mut stack = Vec::new();

        stack.push(String::from("c"));
        stack.push(String::from("b"));
        stack.push(String::from("a"));

        let mut i = 1;

        while let Some(s) = stack.pop() {
            if s.len() == n as usize {
                if i == k {
                    stack.push(s);
                    break;
                };

                i += 1;
                continue;
            }

            for &c in chars.iter().rev() {
                if c != s.chars().last().unwrap() {
                    stack.push(format!("{}{}", s, c));
                }
            }
        }

        stack.pop().unwrap_or(String::from(""))
    }
}
// @leet end

