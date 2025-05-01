impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        // Create a dummy head for the result linked list
        let mut dummy_head = Box::new(ListNode::new(0));
        let mut current = &mut dummy_head;
        
        // Initialize carry
        let mut carry = 0;
        
        // Initialize mutable references to our input lists
        let mut p1 = l1;
        let mut p2 = l2;
        
        // Process both linked lists until we reach the end of both
        while p1.is_some() || p2.is_some() || carry > 0 {
            // Get values from current nodes (or 0 if we've reached the end)
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
            let digit = sum % 10;
            
            // Create new node with current digit
            current.next = Some(Box::new(ListNode::new(digit)));
            current = current.next.as_mut().unwrap();
            
            // Move to next nodes if available
            p1 = match p1 {
                Some(node) => node.next,
                None => None,
            };
            
            p2 = match p2 {
                Some(node) => node.next,
                None => None,
            };
        }
        
        // Return result list (skip the dummy head)
        dummy_head.next
    }
}