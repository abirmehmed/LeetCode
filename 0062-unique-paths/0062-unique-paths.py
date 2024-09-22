class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # Create a 2D array with all elements initialized to 1
        dp = [[1] * n for _ in range(m)]
        
        # Iterate through the array starting from (1, 1)
        for i in range(1, m):
            for j in range(1, n):
                # The number of unique paths to reach (i, j) is the sum of the paths
                # to reach the cell above it (i-1, j) and the cell to the left of it (i, j-1)
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        
        # The bottom-right corner will have the total number of unique paths
        return dp[m-1][n-1]
