use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::build_bst(&nums, 0, nums.len() as i32 - 1)
    }
    
    fn build_bst(nums: &Vec<i32>, left: i32, right: i32) -> Option<Rc<RefCell<TreeNode>>> {
        // Base case: if left > right, return None (empty subtree)
        if left > right {
            return None;
        }
        
        // Find middle element to make it the root
        let mid = left + (right - left) / 2;
        
        // Create root node with the middle element
        let mut root = TreeNode::new(nums[mid as usize]);
        
        // Recursively build left and right subtrees
        root.left = Self::build_bst(nums, left, mid - 1);
        root.right = Self::build_bst(nums, mid + 1, right);
        
        // Return the tree wrapped in Option<Rc<RefCell<>>>
        Some(Rc::new(RefCell::new(root)))
    }
}