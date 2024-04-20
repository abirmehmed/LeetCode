class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int sign = 1;
        long long result = 0;

        // Ignore leading whitespaces
        while (index < s.length() && s[index] == ' ') {
            index++;
        }

        // Determine the sign
        if (index < s.length() && (s[index] == '+' || s[index] == '-')) {
            sign = (s[index] == '+') ? 1 : -1;
            index++;
        }

        // Convert digits to integer
        while (index < s.length() && isdigit(s[index])) {
            int digit = s[index] - '0';
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            index++;
        }

        return static_cast<int>(result * sign);
    }
};
