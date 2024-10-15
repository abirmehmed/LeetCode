/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;

        // Helper function for in-order traversal
        std::function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;

            // Traverse the left subtree
            inorder(node->left);

            // Find the first and second swapped nodes
            if (prev && prev->val > node->val) {
                if (!first) {
                    first = prev;  // First time we find a problem
                }
                second = node;  // Always update the second node
            }
            prev = node;  // Update the previous node

            // Traverse the right subtree
            inorder(node->right);
        };

        // Perform in-order traversal
        inorder(root);

        // Swap the values of the first and second nodes
        if (first && second) {
            std::swap(first->val, second->val);
        }
    }
};