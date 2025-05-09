use std::collections::HashMap;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut char_indices = HashMap::new();
        let mut max_len = 0;
        let mut start = 0;
        
        for (end, ch) in s.chars().enumerate() {
            // If the character is seen and its index is >= start, move start
            if let Some(&prev_index) = char_indices.get(&ch) {
                start = start.max(prev_index + 1);
            }
            
            // Update the character's last seen index
            char_indices.insert(ch, end);
            
            // Calculate current window length
            max_len = max_len.max((end - start + 1) as i32);
        }
        
        max_len
    }
}