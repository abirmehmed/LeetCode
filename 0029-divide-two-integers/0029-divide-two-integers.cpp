class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle special cases
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Get the sign of the result
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        // Convert dividend and divisor to positive values
        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        
        long long quotient = 0;
        
        // Perform repeated subtraction
        while (dvd >= dvs) {
            long long temp = dvs, count = 1;
            while ((dvd - (temp << 1)) >= 0) {
                temp <<= 1;
                count <<= 1;
            }
            dvd -= temp;
            quotient += count;
        }
        
        // Apply the sign and handle overflow
        quotient = (sign == -1) ? -quotient : quotient;
        return (quotient < INT_MIN || quotient > INT_MAX) ? INT_MAX : quotient;
    }
};