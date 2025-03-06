// @leet start
use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn recover_from_preorder(traversal: String) -> Option<Rc<RefCell<TreeNode>>> {
        fn traverse(labels: &[(usize, i32)]) -> Option<Rc<RefCell<TreeNode>>> {
            if labels.is_empty() {
                return None;
            }

            if labels.len() == 1 {
                return Some(Rc::new(RefCell::new(TreeNode {
                    val: labels[0].1,
                    left: None,
                    right: None,
                })));
            }

            let depth = labels[1].0;
            let offset = labels[2..]
                .iter()
                .position(|(d, _)| d == &depth)
                .map(|pos| pos + 2)
                .unwrap_or(labels.len());

            Some(Rc::new(RefCell::new(TreeNode {
                val: labels[0].1,
                left: traverse(&labels[1..offset]),
                right: traverse(&labels[offset..]),
            })))
        }

        let mut labels = Vec::new();

        let mut depth = 0;
        let mut last = String::new();

        for c in traversal.chars() {
            if c.is_ascii_digit() {
                last.push(c);
            } else if !last.is_empty() {
                labels.push((depth, last.parse().unwrap()));
                last.clear();
                depth = 1;
            } else {
                depth += 1;
            }
        }

        if !last.is_empty() {
            labels.push((depth, last.parse().unwrap()));
        }

        traverse(&labels)
    }
}
// @leet end
