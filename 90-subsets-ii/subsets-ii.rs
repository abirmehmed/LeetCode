impl Solution {
    pub fn subsets_with_dup(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums = nums;
        nums.sort(); // Sort the array to handle duplicates
        let mut result = Vec::new();
        let mut current_subset = Vec::new();
        Self::backtrack(&nums, 0, &mut current_subset, &mut result);
        result
    }

    fn backtrack(
        nums: &Vec<i32>,
        start: usize,
        current_subset: &mut Vec<i32>,
        result: &mut Vec<Vec<i32>>,
    ) {
        // Add the current subset to the result
        result.push(current_subset.clone());

        // Iterate through the array
        for i in start..nums.len() {
            // Skip duplicates
            if i > start && nums[i] == nums[i - 1] {
                continue;
            }

            // Include nums[i] in the current subset
            current_subset.push(nums[i]);

            // Recurse with the next index
            Self::backtrack(nums, i + 1, current_subset, result);

            // Backtrack: remove nums[i] from the current subset
            current_subset.pop();
        }
    }
}