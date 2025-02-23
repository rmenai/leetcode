// @leet start
use std::cell::RefCell;
use std::rc::Rc;
type OptNode = Option<Rc<RefCell<TreeNode>>>;

impl Solution {
    pub fn construct_from_pre_post(preorder: Vec<i32>, postorder: Vec<i32>) -> OptNode {
        construct(&preorder[..], &postorder[..])
    }
}

fn construct(pre: &[i32], post: &[i32]) -> OptNode {
    match pre.len() {
        0 => None,
        1 => Some(Rc::new(RefCell::new(TreeNode::new(pre[0])))),
        n => {
            let root = pre[0];

            let first = pre[1];
            let idx = post.iter().position(|&x| x == first).unwrap();

            let mut out = TreeNode::new(root);
            out.left = construct(&pre[1..=idx + 1], &post[0..=idx]);
            out.right = construct(&pre[idx + 2..], &post[idx + 1..n - 1]);

            Some(Rc::new(RefCell::new(out)))
        }
    }
}
// @leet end

