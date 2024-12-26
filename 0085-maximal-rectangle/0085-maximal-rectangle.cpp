#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Update heights array
                if (matrix[i][j] == '1') {
                    heights[j] += 1; // Increment height
                } else {
                    heights[j] = 0; // Reset height
                }
            }
            // Calculate max area for current row's histogram
            maxArea = std::max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> stack;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!stack.empty() && currentHeight < heights[stack.top()]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                maxArea = std::max(maxArea, height * width);
            }

            stack.push(i);
        }

        return maxArea;
    }
};