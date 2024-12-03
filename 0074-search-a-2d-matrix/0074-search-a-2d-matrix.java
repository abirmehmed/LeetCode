class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // Check if the matrix is empty
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }

        int m = matrix.length; // Number of rows
        int n = matrix[0].length; // Number of columns
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
}