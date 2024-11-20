class Solution {
    public int mySqrt(int x) {
        if (x < 2) return x; // Handle cases for 0 and 1 directly
        
        int left = 2, right = x / 2; // Start binary search range
        while (left <= right) {
            int mid = left + (right - left) / 2; // Prevent overflow
            long square = (long) mid * mid; // Calculate mid squared
            
            if (square == x) {
                return mid; // Found exact square root
            } else if (square < x) {
                left = mid + 1; // Move to the right half
            } else {
                right = mid - 1; // Move to the left half
            }
        }
        
        return right; // The floor of the square root
    }

}