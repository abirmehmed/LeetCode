class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // dp_im1 represents dp[i-1], initialized to dp[0] = 0
        // dp_im2 represents dp[i-2], initialized to infinity (invalid)
        // dp_im3 represents dp[i-3], initialized to infinity (invalid)
        long long dp_im1 = 0;
        long long dp_im2 = 1e18; 
        long long dp_im3 = 1e18; 
        
        for (int i = 1; i <= n; ++i) {
            long long cost = costs[i - 1];
            
            // Find the minimum cost to reach the current step from the last 3 possible steps
            long long min_prev = min({dp_im1 + 1, dp_im2 + 4, dp_im3 + 9});
            
            // Total cost to reach step i
            long long current = cost + min_prev;
            
            // Shift the window for the next iteration
            dp_im3 = dp_im2;
            dp_im2 = dp_im1;
            dp_im1 = current;
        }
        
        // dp_im1 now holds the minimum cost to reach step n
        return dp_im1;
    }
};