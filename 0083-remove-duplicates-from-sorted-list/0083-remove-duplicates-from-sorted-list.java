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
        // If the list is empty or has only one node, return it as is
        if (head == null || head.next == null) {
            return head;
        }

        ListNode current = head; // Start with the head of the list

        while (current != null && current.next != null) {
            // If the current value is equal to the next value, skip the next node
            if (current.val == current.next.val) {
                current.next = current.next.next; // Remove duplicate
            } else {
                current = current.next; // Move to the next node
            }
        }

        return head; // Return the modified list
    }
}

