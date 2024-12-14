import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>(); // To store all subsets
        List<Integer> current = new ArrayList<>(); // To store the current subset
        backtrack(result, current, nums, 0); // Start backtracking from index 0
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> current, int[] nums, int start) {
        // Add the current subset to the result
        result.add(new ArrayList<>(current));

        // Iterate through the remaining elements to create new subsets
        for (int i = start; i < nums.length; i++) {
            current.add(nums[i]); // Include the current element
            backtrack(result, current, nums, i + 1); // Recur with the next index
            current.remove(current.size() - 1); // Backtrack to explore other combinations
        }
    }
}
