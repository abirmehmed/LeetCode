use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        // Returns the height of the subtree, or -1 if unbalanced.
        fn check(node: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
            match node {
                None => 0,
                Some(rc) => {
                    let n = rc.borrow();

                    let left_h = check(&n.left);
                    if left_h == -1 {
                        return -1;
                    }

                    let right_h = check(&n.right);
                    if right_h == -1 {
                        return -1;
                    }

                    if (left_h - right_h).abs() > 1 {
                        return -1;
                    }

                    1 + left_h.max(right_h)
                }
            }
        }

        check(&root) != -1
    }
}