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
    public ListNode swapPairs(ListNode head) {
        // If the list is empty or has only one node, return the head
        if (head == null || head.next == null) {
            return head;
        }
        
        // Initialize the new head of the list
        ListNode newHead = head.next;
        
        // Swap the first two nodes
        ListNode prev = null;
        ListNode curr = head;
        ListNode next = curr.next;
        curr.next = next.next;
        next.next = curr;
        
        // Recursively swap the remaining nodes
        if (curr.next != null) {
            curr.next = swapPairs(curr.next);
        }
        
        // Return the new head of the list
        return newHead;
    }
}