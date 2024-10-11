/**
 * @param {number} n
 * @return {number}
 */
var numTrees = function(n) {
    // Create an array to store the number of unique BSTs for each count of nodes
    const dp = new Array(n + 1).fill(0);
    
    // Base cases
    dp[0] = 1; // One unique BST for zero nodes (empty tree)
    dp[1] = 1; // One unique BST for one node
    
    // Fill dp array using the recursive relation
    for (let nodes = 2; nodes <= n; nodes++) {
        for (let root = 1; root <= nodes; root++) {
            const leftSubtrees = dp[root - 1]; // Number of left subtrees
            const rightSubtrees = dp[nodes - root]; // Number of right subtrees
            dp[nodes] += leftSubtrees * rightSubtrees; // Total unique BSTs with this root
        }
    }
    
    return dp[n]; // Return the result for n nodes
};

// Example usage:
console.log(numTrees(3)); // Output: 5
console.log(numTrees(1)); // Output: 1