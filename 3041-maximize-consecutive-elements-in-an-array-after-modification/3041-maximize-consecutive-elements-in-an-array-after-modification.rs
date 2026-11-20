impl Solution {
    pub fn max_selected_elements(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        // Sort the array so we can process numbers from smallest to largest
        nums.sort_unstable();
        
        // dp[v] will store the maximum length of a consecutive sequence ending at value v.
        // Since max value is 10^6, and we might increase it to 10^6 + 1, 
        // we need an array of size 1,000,002 to be safe.
        let mut dp = vec![0; 1000002];
        let mut max_len = 0;
        
        for &x in &nums {
            let x = x as usize;
            
            // IMPORTANT: We must read the old values BEFORE we update them.
            // This prevents us from using the same element twice (once as x, once as x+1).
            let old_dp_x = dp[x];
            let old_dp_x_minus_1 = dp[x - 1];
            
            // Option 1: Use the element as 'x'
            // It extends the sequence that ended at 'x - 1'
            let new_dp_x = old_dp_x_minus_1 + 1;
            if new_dp_x > dp[x] {
                dp[x] = new_dp_x;
            }
            
            // Option 2: Use the element as 'x + 1'
            // It extends the sequence that ended at 'x' (using the old value)
            let new_dp_x_plus_1 = old_dp_x + 1;
            if new_dp_x_plus_1 > dp[x + 1] {
                dp[x + 1] = new_dp_x_plus_1;
            }
            
            // Keep track of the overall maximum length found so far
            let current_max = dp[x].max(dp[x + 1]);
            if current_max > max_len {
                max_len = current_max;
            }
        }
        
        max_len
    }
}