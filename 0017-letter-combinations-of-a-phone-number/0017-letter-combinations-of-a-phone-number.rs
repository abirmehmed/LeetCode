use std::collections::HashMap;

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        if digits.is_empty() {
            return vec![];
        }

        let mut map = HashMap::new();
        map.insert('2', "abc");
        map.insert('3', "def");
        map.insert('4', "ghi");
        map.insert('5', "jkl");
        map.insert('6', "mno");
        map.insert('7', "pqrs");
        map.insert('8', "tuv");
        map.insert('9', "wxyz");

        let mut result = vec![String::new()];
        for digit in digits.chars() {
            let mut tmp = vec![];
            for str in map[&digit].chars() {
                for item in &result {
                    tmp.push(format!("{}{}", item, str));
                }
            }
            result = tmp;
        }
        result
    }
}
