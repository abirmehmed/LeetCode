#include <vector>
#include <stack>
using namespace std;

// Assuming TreeNode is already defined in the environment

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* current = root;

        while (current != nullptr || !stk.empty()) {
            // Reach the leftmost node of the current node
            while (current != nullptr) {
                stk.push(current);
                current = current->left;
            }

            // Current must be null at this point, so we process the top of the stack
            current = stk.top();
            stk.pop();
            result.push_back(current->val); // Visit the node

            // Now we need to visit the right subtree
            current = current->right;
        }

        return result;
    }
};
