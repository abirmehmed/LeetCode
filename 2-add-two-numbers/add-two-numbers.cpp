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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy head node
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        
        // Initialize carry
        int carry = 0;
        
        // Traverse both linked lists
        while (l1 != nullptr || l2 != nullptr) {
            // Get values from current nodes (or 0 if node is null)
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate sum and new carry
            int sum = x + y + carry;
            carry = sum / 10;  // Integer division in C++
            
            // Create new node with digit value (sum % 10)
            current->next = new ListNode(sum % 10);
            current = current->next;
            
            // Move to next nodes if available
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        // If there's a remaining carry, add a new node
        if (carry > 0) {
            current->next = new ListNode(carry);
        }
        
        // Store the result (excluding dummy head)
        ListNode* result = dummyHead->next;
        
        // Free the dummy head to avoid memory leak
        delete dummyHead;
        
        // Return the result list
        return result;
    }
};