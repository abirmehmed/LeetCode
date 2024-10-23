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
    bool isSymmetric(TreeNode* root) {
        // If the tree is empty, it is symmetric
        if (!root) return true;

        // Start the recursive comparison
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // If both nodes are null, they are symmetric
        if (!left && !right) return true;

        // If one of them is null or their values are different, they are not symmetric
        if (!left || !right || left->val != right->val) return false;

        // Check recursively for mirror symmetry
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};