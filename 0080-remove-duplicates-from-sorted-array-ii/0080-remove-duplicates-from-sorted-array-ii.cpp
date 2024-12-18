#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 2) return nums.size(); // If size is 2 or less, return size

        int k = 2; // Start from the third position
        for (int i = 2; i < nums.size(); i++) {
            // Check if the current number is different from the number at position k-2
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i]; // Place it at the k-th position
                k++; // Increment k
            }
        }

        return k; // Return the new length of the array
    }
};
