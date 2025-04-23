class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map to store number -> index mapping
        unordered_map<int, int> numMap;
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement needed to reach target
            int complement = target - nums[i];
            
            // Check if complement exists in our map
            if (numMap.find(complement) != numMap.end()) {
                // Return the indices of both numbers
                return {numMap[complement], i};
            }
            
            // If no match found, add current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        // No solution found (problem guarantees a solution exists)
        return {};
    }
};