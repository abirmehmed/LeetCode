import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        // Create a hash map to store numbers we've seen and their indices
        Map<Integer, Integer> numMap = new HashMap<>();
        
        // One-pass solution - O(n) time complexity
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            
            // Check if the complement exists in our map
            if (numMap.containsKey(complement)) {
                return new int[] {numMap.get(complement), i};
            }
            
            // Add current number to the map
            numMap.put(nums[i], i);
        }
        
        // No solution found (though the problem guarantees one exists)
        return new int[0];
    }
}