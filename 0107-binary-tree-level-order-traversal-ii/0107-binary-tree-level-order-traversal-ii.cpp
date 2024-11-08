#include <vector>
#include <queue>
#include <algorithm> // For std::reverse

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result; // To store the final bottom-up level order traversal
        if (!root) return result; // If the tree is empty, return an empty result

        queue<TreeNode*> q; // Queue to hold nodes for BFS
        q.push(root); // Start with the root node

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            vector<int> currentLevel; // To store values of the current level

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front(); // Get the front node
                q.pop(); // Remove it from the queue
                currentLevel.push_back(currentNode->val); // Add its value to the current level

                // Add children to the queue for the next level
                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }

            result.push_back(currentLevel); // Add current level to the result
        }

        reverse(result.begin(), result.end()); // Reverse the result for bottom-up order
        return result; // Return the final result
    }
};