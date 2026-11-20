impl Solution {
    pub fn minimize_sum(mut nums: Vec<i32>) -> i32 {
        let n = nums.len();
        
        // Sort the array to easily find the extremes
        nums.sort_unstable();
        
        // Option 1: Change the 2 smallest elements
        let option1 = nums[n - 1] - nums[2];
        
        // Option 2: Change the 2 largest elements
        let option2 = nums[n - 3] - nums[0];
        
        // Option 3: Change the 1 smallest and 1 largest element
        let option3 = nums[n - 2] - nums[1];
        
        // Return the minimum of the three options using Rust's beautiful .min() chaining
        option1.min(option2).min(option3)
    }
}