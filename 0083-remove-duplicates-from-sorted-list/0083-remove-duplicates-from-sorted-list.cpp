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
    ListNode* deleteDuplicates(ListNode* head) {
        // If the list is empty or has only one node, return it as is
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* current = head; // Start with the head of the list

        while (current != nullptr && current->next != nullptr) {
            // If the current value is equal to the next value, skip the next node
            if (current->val == current->next->val) {
                current->next = current->next->next; // Remove duplicate
            } else {
                current = current->next; // Move to the next node
            }
        }

        return head; // Return the modified list
    }
};

// Example usage:
#include <iostream>

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
