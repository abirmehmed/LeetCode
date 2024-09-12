class Solution {
    public boolean canJump(int[] nums) {
        int currentReach = 0; // The farthest position you can reach initially
        int target = nums.length - 1; // The last position you need to reach
        
        for (int i = 0; i <= currentReach; ++i) {
            currentReach = Math.max(currentReach, i + nums[i]); // Update the farthest position you can reach
            if (currentReach >= target) return true; // If you can reach or surpass the last position, return true
        }
        
        return false; // If you can't reach the last position, return false
    }
}
