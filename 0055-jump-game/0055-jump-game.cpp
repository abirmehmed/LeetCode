#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currentReach = 0; // The farthest stone you can reach initially
        int target = nums.size() - 1; // The last stone you need to reach
        
        for (int i = 0; i <= currentReach; ++i) {
            currentReach = max(currentReach, i + nums[i]); // Update the farthest stone you can reach
            if (currentReach >= target) return true; // If you can reach or surpass the last stone, the quest is complete
        }
        
        return false; // If you exhaust all possibilities and can't reach the last stone, the quest fails
    }
};
