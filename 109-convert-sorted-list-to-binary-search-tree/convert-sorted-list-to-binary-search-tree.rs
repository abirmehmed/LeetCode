use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn sorted_list_to_bst(head: Option<Box<ListNode>>) -> Option<Rc<RefCell<TreeNode>>> {
        // Helper function to convert a range of the list to BST
        fn build_bst(mut head: &mut Option<Box<ListNode>>, size: i32) -> Option<Rc<RefCell<TreeNode>>> {
            if size <= 0 {
                return None;
            }
            
            // Recursively build left subtree
            let left = build_bst(head, size / 2);
            
            // Current node becomes the root
            let val = head.as_ref().unwrap().val;
            let mut root = TreeNode::new(val);
            root.left = left;
            
            // Move head to next node for next recursion
            *head = head.as_mut().unwrap().next.take();
            
            // Recursively build right subtree
            root.right = build_bst(head, size - size / 2 - 1);
            
            Some(Rc::new(RefCell::new(root)))
        }
        
        // Count the length of the linked list
        let mut current = &head;
        let mut length = 0;
        while let Some(node) = current {
            length += 1;
            current = &node.next;
        }
        
        // Start the recursive construction
        let mut head_mut = head;
        build_bst(&mut head_mut, length)
    }
}