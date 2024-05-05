#include <vector>
#include <queue>

// Do not redefine ListNode. Use the one from the precompiled header.

struct Compare {
    bool operator()(ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq;

        // Initialize the priority queue with the head of each list
        for (ListNode* list : lists) {
            if (list) pq.push(list);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Extract the smallest element from the queue and add it to the result list
        while (!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;

            if (tail->next) pq.push(tail->next);
        }

        return dummy.next;
    }
};
