class Solution {
    public int divide(int dividend, int divisor) {
        // Handle special cases
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        
        // Get the sign of the result
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        // Convert dividend and divisor to positive values
        long dvd = Math.abs((long)dividend);
        long dvs = Math.abs((long)divisor);
        
        long quotient = 0;
        
        // Perform repeated subtraction
        while (dvd >= dvs) {
            long temp = dvs, count = 1;
            while ((dvd - (temp << 1)) >= 0) {
                temp <<= 1;
                count <<= 1;
            }
            dvd -= temp;
            quotient += count;
        }
        
        // Apply the sign and handle overflow
        quotient = (sign == -1) ? -quotient : quotient;
        return (quotient < Integer.MIN_VALUE || quotient > Integer.MAX_VALUE) ? Integer.MAX_VALUE : (int)quotient;
    }
}