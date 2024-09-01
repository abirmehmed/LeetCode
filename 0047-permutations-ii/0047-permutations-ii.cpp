#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end()); // Sort the array to handle duplicates
        std::vector<bool> used(nums.size(), false);
        std::vector<int> current;
        backtrack(nums, used, current, result);
        return result;
    }

private:
    void backtrack(const std::vector<int>& nums, std::vector<bool>& used, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) continue;
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, used, current, result);
            used[i] = false;
            current.pop_back();
        }
    }
};
