class Solution {
    public int climbStairs(int n) {
        if (n == 1) return 1; // Base case: only one way to climb one step
        if (n == 2) return 2; // Base case: two ways to climb two steps

        int[] dp = new int[n + 1]; // Create an array to store the number of ways
        dp[1] = 1; // One way to climb one step
        dp[2] = 2; // Two ways to climb two steps

        // Fill the dp array using the relation dp[i] = dp[i - 1] + dp[i - 2]
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n]; // The result is in dp[n]
    }

}