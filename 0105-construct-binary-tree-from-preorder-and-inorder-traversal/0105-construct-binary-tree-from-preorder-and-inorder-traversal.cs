

public class Solution {
    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        // Base case: if the arrays are empty, return null
        if (preorder.Length == 0 || inorder.Length == 0) {
            return null;
        }

        // The first element of preorder is the root
        int rootVal = preorder[0];
        TreeNode root = new TreeNode(rootVal);

        // Find the index of the root in inorder array
        int rootIndex = Array.IndexOf(inorder, rootVal);

        // Build left and right subtrees recursively
        // Left subtree: elements before rootIndex in inorder
        // Right subtree: elements after rootIndex in inorder
        root.left = BuildTree(preorder[1..(rootIndex + 1)], inorder[0..rootIndex]);
        root.right = BuildTree(preorder[(rootIndex + 1)..], inorder[(rootIndex + 1)..]);

        return root;
    }
}