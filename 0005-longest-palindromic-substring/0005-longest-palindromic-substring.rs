impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        if s.is_empty() {
            return String::new();
        }

        let n = s.len();
        let mut dp = vec![vec![false; n]; n];
        let mut max_length = 0;
        let mut start = 0;

        for i in 0..n {
            dp[i][i] = true;
            max_length = 1;
            start = i;
        }

        for len in 2..=n {
            for i in 0..n - len + 1 {
                let j = i + len - 1;

                if len == 2 {
                    dp[i][j] = s.as_bytes()[i] == s.as_bytes()[j];
                } else {
                    dp[i][j] = s.as_bytes()[i] == s.as_bytes()[j] && dp[i + 1][j - 1];
                }

                if dp[i][j] && len > max_length {
                    max_length = len;
                    start = i;
                }
            }
        }

        s[start..start + max_length].to_string()
    }
}
