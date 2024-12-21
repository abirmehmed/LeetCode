/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        // Create a dummy node to simplify edge cases
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        ListNode prev = dummy; // Previous node starts at dummy
        ListNode current = head; // Current node starts at head

        while (current != null) {
            // Check if it's a start of duplicates
            if (current.next != null && current.val == current.next.val) {
                // Skip all nodes with the same value
                while (current.next != null && current.val == current.next.val) {
                    current = current.next; // Move to the last duplicate
                }
                // Connect prev to the next distinct node
                prev.next = current.next;
            } else {
                // Move prev to current if no duplicates found
                prev = prev.next;
            }
            // Move current forward
            current = current.next;
        }

        return dummy.next; // Return the new head, which is the next of dummy
    }
}