impl Solution {
    pub fn climb_stairs(n: i32, costs: Vec<i32>) -> i32 {
        // Andy's Smart Memory:
        // dp_im1 = cost to reach the step 1 behind us (starts at 0 for step 0)
        let mut dp_im1 = 0;
        
        // dp_im2 = cost to reach the step 2 behind us (impossible at start, so "infinity")
        let mut dp_im2 = i32::MAX / 2; 
        
        // dp_im3 = cost to reach the step 3 behind us (impossible at start, so "infinity")
        let mut dp_im3 = i32::MAX / 2; 
        
        // Andy hops from step 1 all the way to step n
        for i in 1..=n {
            // The sticky sap cost for the current step (costs is 0-indexed, so step i is at index i-1)
            let cost = costs[(i - 1) as usize];
            
            // Find the cheapest way to get here from the last 3 steps
            let min_prev = (dp_im1 + 1)
                .min(dp_im2 + 4)
                .min(dp_im3 + 9);
            
            // Total cost to land on this step
            let current = cost + min_prev;
            
            // Slide the memory window forward for the next hop!
            dp_im3 = dp_im2;
            dp_im2 = dp_im1;
            dp_im1 = current;
        }
        
        // After the loop, dp_im1 holds the cheapest cost to reach step n
        dp_im1
    }
}