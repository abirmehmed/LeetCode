class Solution {
public:
    string digitSum(string s, int k) {
        // Keep doing rounds as long as the string is longer than k
        while (s.length() > k) {
            string new_s = "";
            
            // Divide s into groups of size k
            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;
                
                // Sum the digits in the current group
                // (The last group might be smaller than k, which is handled by j < s.length())
                for (int j = i; j < i + k && j < s.length(); ++j) {
                    sum += s[j] - '0'; // Convert char digit to integer
                }
                
                // Convert the sum back to a string and append it
                new_s += to_string(sum);
            }
            
            // Update s for the next round
            s = new_s;
        }
        
        return s;
    }
};