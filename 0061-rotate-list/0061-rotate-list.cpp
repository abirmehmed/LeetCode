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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        // Calculate the length of the list
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Make the list circular
        tail->next = head;

        // Find the new tail: (length - k % length - 1)th node
        // and the new head: (length - k % length)th node
        k = k % length;
        for (int i = 0; i < length - k; i++) {
            tail = tail->next;
        }

        // Break the circle
        head = tail->next;
        tail->next = nullptr;

        return head;
    }
};
