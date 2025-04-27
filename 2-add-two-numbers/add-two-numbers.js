/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    // Initialize a dummy head for the result linked list
    let dummyHead = new ListNode(0);
    let current = dummyHead;
    
    // Initialize carry value
    let carry = 0;
    
    // Traverse both linked lists
    while (l1 !== null || l2 !== null) {
        // Get values from the current nodes (or 0 if node is null)
        let x = l1 !== null ? l1.val : 0;
        let y = l2 !== null ? l2.val : 0;
        
        // Calculate sum and new carry
        let sum = x + y + carry;
        carry = Math.floor(sum / 10);
        
        // Create a new node with digit value (sum % 10)
        current.next = new ListNode(sum % 10);
        current = current.next;
        
        // Move to next nodes if available
        if (l1 !== null) l1 = l1.next;
        if (l2 !== null) l2 = l2.next;
    }
    
    // If there's a remaining carry, add a new node
    if (carry > 0) {
        current.next = new ListNode(carry);
    }
    
    // Return the result list (excluding the dummy head)
    return dummyHead.next;
};