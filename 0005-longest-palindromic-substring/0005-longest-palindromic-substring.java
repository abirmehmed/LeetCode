class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }

        int n = s.length();
        boolean[][] dp = new boolean[n][n];
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
                    dp[i][j] = (s.charAt(i) == s.charAt(j));
                } else {
                    dp[i][j] = (s.charAt(i) == s.charAt(j)) && dp[i + 1][j - 1];
                }

                if (dp[i][j] && len > maxLength) {
                    maxLength = len;
                    start = i;
                }
            }
        }

        return s.substring(start, start + maxLength);
    }
}
