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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result; // To store the final zigzag order traversal
        if (!root) return result; // If the tree is empty, return an empty result

        queue<TreeNode*> q; // Queue to hold nodes for BFS
        q.push(root); // Start with the root node
        bool leftToRight = true; // Flag to track direction of traversal

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            vector<int> currentLevel(levelSize); // To store values of the current level

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front(); // Get the front node
                q.pop(); // Remove it from the queue
                
                // Determine position based on direction
                if (leftToRight) {
                    currentLevel[i] = currentNode->val; // Left to right
                } else {
                    currentLevel[levelSize - 1 - i] = currentNode->val; // Right to left
                }

                // Add children to the queue for the next level
                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }

            result.push_back(currentLevel); // Add current level to the result
            leftToRight = !leftToRight; // Toggle direction for next level
        }

        return result; // Return the final result
    }
};