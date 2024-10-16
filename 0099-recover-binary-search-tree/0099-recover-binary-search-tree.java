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
    private TreeNode first = null;
    private TreeNode second = null;
    private TreeNode prev = null;

    public void recoverTree(TreeNode root) {
        inorderTraversal(root);
        // Swap the values of the two nodes identified
        if (first != null && second != null) {
            int temp = first.val;
            first.val = second.val;
            second.val = temp;
        }
    }

    private void inorderTraversal(TreeNode root) {
        if (root == null) return;

        // Traverse the left subtree
        inorderTraversal(root.left);

        // If this node is smaller than the previous node, it's violating the BST rule
        if (prev != null && root.val < prev.val) {
            // If it's the first violation, mark these two nodes as first and second
            if (first == null) {
                first = prev;
            }
            // Always update second to the current node
            second = root;
        }

        // Update prev to the current node before moving to the right subtree
        prev = root;

        // Traverse the right subtree
        inorderTraversal(root.right);
    }
}