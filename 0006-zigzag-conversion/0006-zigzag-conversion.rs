impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 || s.len() <= num_rows as usize {
            return s;
        }

        let mut result = String::new();
        let step = 2 * num_rows - 2;

        for row in 0..num_rows {
            for i in (row as usize)..s.len() {
                if (i - row as usize) % step as usize == 0 {
                    result.push(s.as_bytes()[i] as char);
                } else if row > 0 && row < num_rows - 1 && (i - row as usize) % step as usize == (step - 2 * row) as usize {
                    result.push(s.as_bytes()[i] as char);
                }
            }
        }

        result
    }
}
