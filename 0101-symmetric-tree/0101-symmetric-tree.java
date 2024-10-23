/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        // If the tree is empty, it is symmetric
        if (root == null) return true;

        // Start the recursive comparison
        return isMirror(root.left, root.right);
    }

    private boolean isMirror(TreeNode left, TreeNode right) {
        // If both nodes are null, they are symmetric
        if (left == null && right == null) return true;

        // If one of them is null or their values are different, they are not symmetric
        if (left == null || right == null || left.val != right.val) return false;

        // Check recursively for mirror symmetry
        return isMirror(left.left, right.right) && isMirror(left.right, right.left);
    }
}