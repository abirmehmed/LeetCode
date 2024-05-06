/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If the list is empty or has only one node, return the head
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Store the new head of the list
        ListNode* newHead = head->next;
        
        // Swap the first two nodes
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        
        // Return the new head of the list
        return newHead;
    }
};