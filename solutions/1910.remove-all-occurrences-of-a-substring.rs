// @leet start
impl Solution {
    pub fn remove_occurrences(s:    pub fn remove_occurrences(s: String, part: String) -> String {
        let pattern: Vec<char> = part.chars().rev().collect();

        let mut stack = Vec::new();
        for c in s.chars().rev() {
            stack.push(c);

            while stack.len() >= 3 && stack[stack.len() - 3..] == pattern {
                stack.pop();
                stack.pop();
                stack.pop();
            }
        }

        stack.iter().collect::<String>()
    }
     pub fn remove_occurrences(s: String, part: String) -> String {
        let pattern: Vec<char> = part.chars().rev().collect();

        let mut stack = Vec::new();
        for c in s.chars().rev() {
            stack.push(c);

            while stack.len() >= 3 && stack[stack.len() - 3..] == pattern {
                stack.pop();
                stack.pop();
                stack.pop();
            }
        }

        stack.iter().collect::<String>()
    }
S    pub fn remove_occurrences(s: String, part: String) -> String {
        let pattern: Vec<char> = part.chars().rev().collect();

        let mut stack = Vec::new();
        for c in s.chars().rev() {
            stack.push(c);

            while stack.len() >= 3 && stack[stack.len() - 3..] == pattern {
                stack.pop();
                stack.pop();
                stack.pop();
            }
        }

        stack.iter().collect::<String>()
    }
t    pub fn remove_occurrences(s: String, part: String) -> String {
        let pattern: Vec<char> = part.chars().rev().collect();

        let mut stack = Vec::new();
        for c in s.chars().rev() {
            stack.push(c);

            while stack.len() >= 3 && stack[stack.len() - 3..] == pattern {
                stack.pop();
                stack.pop();
                stack.pop();
            }
        }

        stack.iter().collect::<String>()
    }
r    pub fn remove_occurrences(s: String, part: String) -> String {
        let pattern: Vec<char> = part.chars().rev().collect();

        let mut stack = Vec::new();
        for c in s.chars().rev() {
            stack.push(c);

            while stack.len() >= 3 && stack[stack.len() - 3..] == pattern {
                stack.pop();
                stack.pop();
                stack.pop();
            }
        }

        stack.iter().collect::<String>()
    }
i    pub fn remove_occurrences(s: String, part: String) -> String {
        let pattern: Vec<char> = part.chars().rev().collect();

        let mut stack = Vec::new();
        for c in s.chars().rev() {
            stack.push(c);

            while stack.len() >= 3 && stack[stack.len() - 3..] == pattern {
                stack.pop();
                stack.pop();
                stack.pop();
            }
        }

        stack.iter().collect::<String>()
    }
n    pub fn remove_occurrences(s: String, part: String) -> String {
        let pattern: Vec<char> = part.chars().rev().collect();

        let mut stack = Vec::new();
        for c in s.chars().rev() {
            stack.push(c);

            while stack.len() >= 3 && stack[stack.len() - 3..] == pattern {
                stack.pop();
                stack.pop();
                stack.pop();
            }
        }

        stack.iter().collect::<String>()
    }
g    pub fn remove_occurrences(s: String, part: String) -> String {
        let pattern: Vec<char> = part.chars().rev().collect();

        let mut stack = Vec::new();
        for c in s.chars().rev() {
            stack.push(c);

            while stack.len() >= 3 && stack[stack.len() - 3..] == pattern {
                stack.pop();
                stack.pop();
                stack.pop();
            }
        }

        stack.iter().collect::<String>()
    }
,    pub fn remove_occurrences(s: String, part: String) -> String {
        let pattern: Vec<char> = part.chars().rev().collect();

        let mut stack = Vec::new();
        for c in s.chars().rev() {
            stack.push(c);

            while stack.len() >= 3 && stack[stack.len() - 3..] == pattern {
                stack.pop();
                stack.pop();
                stack.pop();
            }
        }

        stack.iter().collect::<String>()
    }
 part: String) -> String {}
}
// @leet end

