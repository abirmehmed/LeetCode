# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # Helper function to validate the BST
        def isValidBSTHelper(node, min_val, max_val):
            if not node:
                return True  # An empty node is a valid BST
            
            # Current node's value must be within the valid range
            if node.val <= min_val or node.val >= max_val:
                return False
            
            # Recursively check the left and right subtrees
            return (isValidBSTHelper(node.left, min_val, node.val) and
                    isValidBSTHelper(node.right, node.val, max_val))
        
        # Start the recursion with the entire range of values
        return isValidBSTHelper(root, float('-inf'), float('inf'))