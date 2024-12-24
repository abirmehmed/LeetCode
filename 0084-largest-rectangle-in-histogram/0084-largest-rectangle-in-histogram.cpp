#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> indices; // Stack to store indices of heights
        int maxArea = 0; // Variable to keep track of maximum area
        int n = heights.size(); // Number of bars in histogram

        for (int i = 0; i <= n; ++i) {
            // Use 0 as a sentinel for easier calculations
            int currentHeight = (i == n) ? 0 : heights[i];

            // While there are bars in the stack and current height is less than
            // height of bar at index stored at top of stack
            while (!indices.empty() && currentHeight < heights[indices.top()]) {
                int height = heights[indices.top()];
                indices.pop();

                // Determine width
                int width = indices.empty() ? i : i - indices.top() - 1;

                // Calculate area
                maxArea = std::max(maxArea, height * width);
            }

            // Push current index onto stack
            indices.push(i);
        }

        return maxArea; // Return maximum area found
    }
};
