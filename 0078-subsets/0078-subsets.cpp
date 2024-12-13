#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result; // To store all subsets
        std::vector<int> current; // To store the current subset
        backtrack(result, current, nums, 0); // Start backtracking from index 0
        return result;
    }

private:
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& current, const std::vector<int>& nums, int start) {
        // Add the current subset to the result
        result.push_back(current);

        // Iterate through the remaining elements to create new subsets
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]); // Include the current element
            backtrack(result, current, nums, i + 1); // Recur with the next index
            current.pop_back(); // Backtrack to explore other combinations
        }
    }
};