class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2; // Start from the second-to-last element

        // Find the first decreasing element from right to left
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Find the smallest element greater than nums[i] to its right
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // Reverse the subarray from i+1 to the end
        reverse(nums.begin() + i + 1, nums.end());
    }
};
