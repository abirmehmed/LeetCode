class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return buildBST(nums, 0, nums.length - 1);
    }
    
    private TreeNode buildBST(int[] nums, int left, int right) {
        // Base case: if left > right, return null (empty subtree)
        if (left > right) {
            return null;
        }
        
        // Find middle element to make it the root
        int mid = left + (right - left) / 2;
        
        // Create root node with the middle element
        TreeNode root = new TreeNode(nums[mid]);
        
        // Recursively build left and right subtrees
        root.left = buildBST(nums, left, mid - 1);
        root.right = buildBST(nums, mid + 1, right);
        
        return root;
    }
}