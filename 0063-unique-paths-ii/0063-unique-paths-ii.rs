impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let m = obstacle_grid.len();
        let n = obstacle_grid[0].len();
        
        // If the starting point or the ending point is an obstacle, return 0
        if obstacle_grid[0][0] == 1 || obstacle_grid[m-1][n-1] == 1 {
            return 0;
        }
        
        // Create a 2D dp array initialized to 0
        let mut dp = vec![vec![0; n]; m];
        
        // Initialize the starting point
        dp[0][0] = 1;
        
        // Fill the dp array
        for i in 0..m {
            for j in 0..n {
                if obstacle_grid[i][j] == 1 {
                    dp[i][j] = 0;
                } else {
                    if i > 0 {
                        dp[i][j] += dp[i-1][j];
                    }
                    if j > 0 {
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
        }
        
        dp[m-1][n-1]
    }
}
