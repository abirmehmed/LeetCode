import java.util.HashMap;
import java.util.Map;

class Solution {
    // Method to find two numbers that add up to the target
    public int[] twoSum(int[] nums, int target) {
        // Create a HashMap to store numbers and their indices
        // Key: the number from the array
        // Value: the index of that number in the array
        Map<Integer, Integer> numMap = new HashMap<>();
        
        // Loop through each number in the array
        for(int i = 0; i < nums.length; i++) {
            // Calculate the complement - the number we need to find 
            // to pair with nums[i] to reach the target
            int complement = target - nums[i];
            
            // Check if we've already seen the complement in our map
            if (numMap.containsKey(complement)) {
                // If found, return the indices of the complement and current number
                return new int[]{numMap.get(complement), i};
            }
            
            // If complement not found, store the current number and its index in the map
            numMap.put(nums[i], i);
        }
        
        // If no solution found (though problem states there is exactly one solution)
        return new int[0];
    }
}