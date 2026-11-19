#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        
        // Sort the array to easily find the extremes
        sort(nums.begin(), nums.end());
        
        // Option 1: Change the 2 smallest elements
        // The new max difference will be between the largest and the 3rd smallest
        int option1 = nums[n - 1] - nums[2];
        
        // Option 2: Change the 2 largest elements
        // The new max difference will be between the 3rd largest and the smallest
        int option2 = nums[n - 3] - nums[0];
        
        // Option 3: Change the 1 smallest and 1 largest element
        // The new max difference will be between the 2nd largest and 2nd smallest
        int option3 = nums[n - 2] - nums[1];
        
        // Return the minimum of the three options
        return min({option1, option2, option3});
    }
};