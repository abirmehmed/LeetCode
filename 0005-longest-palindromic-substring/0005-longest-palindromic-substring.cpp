class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            maxLength = 1;
            start = i;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;

                if (len == 2) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }

                if (dp[i][j] && len > maxLength) {
                    maxLength = len;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};
