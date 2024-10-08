class Solution {
public:
    int numTrees(int n) {
        // Create a DP array to store the number of unique BSTs for each number of nodes
        std::vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = 1; // There is one unique BST with 0 nodes (an empty tree)
        dp[1] = 1; // There is one unique BST with 1 node
        
        // Fill the DP array
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        
        return dp[n];
    }
};
