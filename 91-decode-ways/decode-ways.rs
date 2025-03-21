impl Solution {
    pub fn num_decodings(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        if n == 0 {
            return 0;
        }
        
        let mut dp = vec![0; n + 1];
        dp[0] = 1;
        
        for i in 1..=n {
            // Check if the current single digit is valid
            if s[i-1] != b'0' {
                dp[i] += dp[i-1];
            }
            
            // Check if the current and previous digits form a valid two-digit number
            if i >= 2 {
                let two_digit = (s[i-2] - b'0') * 10 + (s[i-1] - b'0');
                if two_digit >= 10 && two_digit <= 26 {
                    dp[i] += dp[i-2];
                }
            }
        }
        
        dp[n]
    }
}