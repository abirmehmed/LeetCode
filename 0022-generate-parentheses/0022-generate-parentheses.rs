impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut result = Vec::new();
        Self::backtrack(&mut result, String::new(), 0, 0, n as usize);
        result
    }

    fn backtrack(result: &mut Vec<String>, current: String, open: usize, close: usize, max: usize) {
        if current.len() == max * 2 {
            result.push(current);
            return;
        }

        if open < max {
            Self::backtrack(result, format!("{}(", current), open + 1, close, max);
        }
        if close < open {
            Self::backtrack(result, format!("{})", current), open, close + 1, max);
        }
    }
}
