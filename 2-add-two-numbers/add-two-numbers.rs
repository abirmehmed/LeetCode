// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        // Create a dummy head node to simplify the logic
        let mut dummy_head = ListNode::new(0);
        let mut current = &mut dummy_head;
        
        // Variables to track the current nodes and carry
        let mut p1 = l1;
        let mut p2 = l2;
        let mut carry = 0;
        
        // Continue until both lists are exhausted and there's no carry
        while p1.is_some() || p2.is_some() || carry > 0 {
            // Get values from current nodes or use 0 if node doesn't exist
            let x = match &p1 {
                Some(node) => node.val,
                None => 0,
            };
            
            let y = match &p2 {
                Some(node) => node.val,
                None => 0,
            };
            
            // Calculate sum and new carry
            let sum = x + y + carry;
            carry = sum / 10;
            
            // Create new node with the digit (sum % 10)
            current.next = Some(Box::new(ListNode::new(sum % 10)));
            current = current.next.as_mut().unwrap();
            
            // Move to next nodes if they exist
            p1 = match p1 {
                Some(node) => node.next,
                None => None,
            };
            
            p2 = match p2 {
                Some(node) => node.next,
                None => None,
            };
        }
        
        // Return the result linked list (skipping the dummy head)
        dummy_head.next
    }
}