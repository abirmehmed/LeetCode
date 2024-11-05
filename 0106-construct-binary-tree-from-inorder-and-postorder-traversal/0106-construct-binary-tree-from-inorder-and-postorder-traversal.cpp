#include <vector>
#include <unordered_map>
#include <memory>

using namespace std;

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
    // Map to store indices of inorder elements
    unordered_map<int, int> inorderIndexMap;

    // Helper function to build tree recursively
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex) {
        // Base case: if there are no elements to construct
        if (inStart > inEnd) return nullptr;

        // The last element in postorder is the root
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of this root in inorder
        int rootIndex = inorderIndexMap[rootVal];

        // Recursively construct right and left subtrees
        root->right = buildTreeHelper(inorder, postorder, rootIndex + 1, inEnd, postIndex);
        root->left = buildTreeHelper(inorder, postorder, inStart, rootIndex - 1, postIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Fill map with indices of inorder elements
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1; // Start from the last element of postorder
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, postIndex);
    }
};