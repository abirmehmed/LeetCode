impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        let len1 = num1.len();
        let len2 = num2.len();
        let mut result = vec![0; len1 + len2];

        let num1_bytes = num1.as_bytes();
        let num2_bytes = num2.as_bytes();

        for i in (0..len1).rev() {
            for j in (0..len2).rev() {
                let mul = (num1_bytes[i] - b'0') as usize * (num2_bytes[j] - b'0') as usize;
                let sum = mul + result[i + j + 1];

                result[i + j] += sum / 10;
                result[i + j + 1] = sum % 10;
            }
        }

        let mut result_str = String::new();
        let mut leading_zero = true;

        for &num in &result {
            if !(leading_zero && num == 0) {
                leading_zero = false;
                result_str.push((num as u8 + b'0') as char);
            }
        }

        if result_str.is_empty() {
            return "0".to_string();
        }

        result_str
    }
}
