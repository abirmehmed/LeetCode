import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>(); // To store the final zigzag order traversal
        if (root == null) return result; // If the tree is empty, return an empty result

        Queue<TreeNode> queue = new LinkedList<>(); // Queue to hold nodes for BFS
        queue.offer(root); // Start with the root node
        boolean leftToRight = true; // Flag to track direction of traversal

        while (!queue.isEmpty()) {
            int levelSize = queue.size(); // Number of nodes at the current level
            List<Integer> currentLevel = new ArrayList<>(levelSize); // To store values of the current level

            for (int i = 0; i < levelSize; i++) {
                TreeNode currentNode = queue.poll(); // Get the front node
                
                // Determine position based on direction
                if (leftToRight) {
                    currentLevel.add(currentNode.val); // Left to right
                } else {
                    currentLevel.add(0, currentNode.val); // Right to left (add at the beginning)
                }

                // Add children to the queue for the next level
                if (currentNode.left != null) queue.offer(currentNode.left);
                if (currentNode.right != null) queue.offer(currentNode.right);
            }

            result.add(currentLevel); // Add current level to the result
            leftToRight = !leftToRight; // Toggle direction for next level
        }

        return result; // Return the final result
    }
}