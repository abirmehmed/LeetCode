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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            if (count % k == 0) {
                prev = reverseOneGroup(prev, curr->next);
                curr = prev->next;
            } else {
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
    
private:
    ListNode* reverseOneGroup(ListNode* prev, ListNode* next) {
        ListNode* last = prev->next;
        ListNode* curr = last->next;
        
        while (curr != next) {
            last->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = last->next;
        }
        
        return last;
    }
};