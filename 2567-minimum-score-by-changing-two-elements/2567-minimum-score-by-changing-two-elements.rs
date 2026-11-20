impl Solution {
    pub fn minimize_sum(mut nums: Vec<i32>) -> i32 {
        // 1. Sort the array so the extremes are at the edges
        nums.sort();
        let n = nums.len();

        // 2. The three choices for which 2 numbers to change:

        // Choice 1: Change the 2 smallest -> gap is between largest and 3rd smallest
        let option1 = nums[n - 1] - nums[2];

        // Choice 2: Change the 2 largest  -> gap is between 3rd largest and smallest
        let option2 = nums[n - 3] - nums[0];

        // Choice 3: Change 1 smallest + 1 largest -> gap is between 2nd largest and 2nd smallest
        let option3 = nums[n - 2] - nums[1];

        // 3. Return the smallest gap (the Low score is always 0)
        option1.min(option2).min(option3)
    }
}