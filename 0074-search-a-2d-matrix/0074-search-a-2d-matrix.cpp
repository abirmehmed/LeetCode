class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false; // Handle empty matrix case
        }

        int m = matrix.size(); // Number of rows
        int n = matrix[0].size(); // Number of columns
        int low = 0;
        int high = m * n - 1; // Total number of elements - 1

        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid overflow
            int midValue = matrix[mid / n][mid % n]; // Convert mid to 2D indices

            if (midValue == target) {
                return true; // Target found
            } else if (midValue < target) {
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }

        return false; // Target not found
    }
};