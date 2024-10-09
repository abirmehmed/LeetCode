class Solution {
    public int numTrees(int n) {
        // Create an array to store the number of unique BSTs for each number of nodes
        int[] dp = new int[n + 1];
        // Base case: There is one unique BST with 0 nodes (empty tree)
        dp[0] = 1;
        // Base case: There is one unique BST with 1 node
        dp[1] = 1;
        
        // Fill the dp array using the recursive formula
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        
        // Return the number of unique BSTs with n nodes
        return dp[n];
    }
}
