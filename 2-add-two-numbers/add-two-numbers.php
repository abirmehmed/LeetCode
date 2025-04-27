/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {

    /**
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function addTwoNumbers($l1, $l2) {
        // Create a dummy head node
        $dummyHead = new ListNode(0);
        $current = $dummyHead;
        
        // Initialize carry
        $carry = 0;
        
        // Traverse both linked lists
        while ($l1 !== null || $l2 !== null) {
            // Get values from current nodes (or 0 if node is null)
            $x = ($l1 !== null) ? $l1->val : 0;
            $y = ($l2 !== null) ? $l2->val : 0;
            
            // Calculate sum and new carry
            $sum = $x + $y + $carry;
            $carry = intval($sum / 10);  // In PHP we use intval() instead of Math.floor()
            
            // Create new node with digit value (sum % 10)
            $current->next = new ListNode($sum % 10);
            $current = $current->next;
            
            // Move to next nodes if available
            if ($l1 !== null) $l1 = $l1->next;
            if ($l2 !== null) $l2 = $l2->next;
        }
        
        // If there's a remaining carry, add a new node
        if ($carry > 0) {
            $current->next = new ListNode($carry);
        }
        
        // Return the result list (excluding the dummy head)
        return $dummyHead->next;
    }
}