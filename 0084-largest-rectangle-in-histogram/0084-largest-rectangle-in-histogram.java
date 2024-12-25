import java.util.Stack;

class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>(); // Stack to store indices of heights
        int maxArea = 0; // Variable to keep track of maximum area
        int n = heights.length; // Number of bars in histogram

        for (int i = 0; i <= n; i++) {
            // Use 0 as a sentinel for easier calculations
            int currentHeight = (i == n) ? 0 : heights[i];

            // While there are bars in the stack and current height is less than
            // height of bar at index stored at top of stack
            while (!stack.isEmpty() && currentHeight < heights[stack.peek()]) {
                int height = heights[stack.pop()]; // The height of the rectangle
                // Determine width
                int width = stack.isEmpty() ? i : i - stack.peek() - 1;

                // Calculate area and update maxArea
                maxArea = Math.max(maxArea, height * width);
            }

            // Push current index onto stack
            stack.push(i);
        }

        return maxArea; // Return maximum area found
    }
}
