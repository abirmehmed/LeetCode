impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let mut index = 0;
        let mut sign = 1;
        let mut result = 0;

        // Ignore leading whitespaces
        while index < s.len() && s.as_bytes()[index] == b' ' {
            index += 1;
        }

        // Determine the sign
        if index < s.len() && (s.as_bytes()[index] == b'+' || s.as_bytes()[index] == b'-') {
            sign = if s.as_bytes()[index] == b'-' { -1 } else { 1 };
            index += 1;
        }

        // Convert digits to integer
        while index < s.len() && s.as_bytes()[index] >= b'0' && s.as_bytes()[index] <= b'9' {
            let digit = (s.as_bytes()[index] - b'0') as i32;
            if result > i32::MAX / 10 || (result == i32::MAX / 10 && digit > 7) {
                return if sign == 1 { i32::MAX } else { i32::MIN };
            }
            result = result * 10 + digit;
            index += 1;
        }

        result * sign
    }
}
