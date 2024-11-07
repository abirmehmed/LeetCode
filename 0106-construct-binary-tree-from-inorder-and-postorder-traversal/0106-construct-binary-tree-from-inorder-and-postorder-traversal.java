// Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    // Constructor with one parameter
    public TreeNode(int val) {
        this.val = val;
        this.left = null;  // Initialize left child as null
        this.right = null; // Initialize right child as null
    }

    // Constructor with three parameters
    public TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    private int postIndex; // To keep track of the current index in postorder

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        // Initialize postIndex to the last index of postorder array
        postIndex = postorder.length - 1;

        // Create a map to store indices of inorder elements for quick lookup
        java.util.HashMap<Integer, Integer> inorderIndexMap = new java.util.HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            inorderIndexMap.put(inorder[i], i);
        }

        // Call the recursive helper function to build the tree
        return buildTreeHelper(inorder, postorder, 0, inorder.length - 1, inorderIndexMap);
    }

    private TreeNode buildTreeHelper(int[] inorder, int[] postorder, int inStart, int inEnd,
                                      java.util.HashMap<Integer, Integer> inorderIndexMap) {
        // Base case: if there are no elements to construct the tree
        if (inStart > inEnd) {
            return null;
        }

        // The last element in postorder is the root node
        int rootVal = postorder[postIndex];
        TreeNode root = new TreeNode(rootVal);

        // Decrement postIndex to point to the next root node in postorder
        postIndex--;

        // Find the index of the root in inorder array
        int rootIndex = inorderIndexMap.get(rootVal);

        // Recursively build the right and left subtrees
        // Build right subtree first because we are using postorder (last element is root)
        root.right = buildTreeHelper(inorder, postorder, rootIndex + 1, inEnd, inorderIndexMap);
        root.left = buildTreeHelper(inorder, postorder, inStart, rootIndex - 1, inorderIndexMap);

        return root;
    }
}

