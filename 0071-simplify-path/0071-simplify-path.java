import java.util.Stack;

class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<>(); // Stack to keep track of valid directories
        String[] tokens = path.split("/"); // Split the path by '/'

        for (String token : tokens) {
            if (token.isEmpty() || token.equals(".")) {
                // Ignore empty tokens and current directory references
                continue;
            } else if (token.equals("..")) {
                // Go up to the parent directory if possible
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            } else {
                // Push valid directory names onto the stack
                stack.push(token);
            }
        }

        // Construct the simplified path
        StringBuilder simplifiedPath = new StringBuilder("/");
        while (!stack.isEmpty()) {
            simplifiedPath.insert(1, stack.pop() + "/"); // Insert at position 1 to avoid leading slash
        }

        // Remove trailing slash if it exists, except for root directory
        if (simplifiedPath.length() > 1) {
            simplifiedPath.setLength(simplifiedPath.length() - 1); // Remove last '/'
        }

        return simplifiedPath.toString();
    }
}