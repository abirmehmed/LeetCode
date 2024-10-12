#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Get the lengths of the strings
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        
        // If the lengths don't match up, s3 can't be an interleaving of s1 and s2
        if (len1 + len2 != len3) {
            return false;
        }

        // Create a DP table
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));

        // Initialize the DP table
        dp[0][0] = true;
        
        // Fill the DP table
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if (i > 0) {
                    dp[i][j] = dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }
                if (j > 0) {
                    dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        
        // The answer is in dp[len1][len2]
        return dp[len1][len2];
    }
};
