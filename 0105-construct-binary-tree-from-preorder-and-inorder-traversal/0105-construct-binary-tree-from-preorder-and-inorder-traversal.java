import java.util.HashMap;

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
    private HashMap<Integer, Integer> inorderIndexMap; // To store indices of inorder elements
    private int preorderIndex; // To keep track of current index in preorder array

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        // Initialize index map
        inorderIndexMap = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            inorderIndexMap.put(inorder[i], i);
        }

        preorderIndex = 0; // Start from the first element in preorder
        return buildTreeHelper(preorder, 0, preorder.length - 1);
    }

    private TreeNode buildTreeHelper(int[] preorder, int left, int right) {
        // Base case: if there are no elements to construct the tree
        if (left > right) return null;

        // The first element in preorder is the root
        int rootVal = preorder[preorderIndex++];
        TreeNode root = new TreeNode(rootVal);

        // Find the index of this root in inorder
        int rootIndex = inorderIndexMap.get(rootVal);

        // Recursively construct left and right subtrees
        root.left = buildTreeHelper(preorder, left, rootIndex - 1);
        root.right = buildTreeHelper(preorder, rootIndex + 1, right);

        return root;
    }
}