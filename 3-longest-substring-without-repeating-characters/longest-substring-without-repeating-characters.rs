impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut last_index = [ -1; 128 ]; // Covers all ASCII characters
        let mut max_len = 0;
        let mut start = 0;

        for (end, ch) in s.chars().enumerate() {
            let ch_as_byte = ch as usize;
            // If the character was seen after `start`, move `start` forward
            start = start.max(last_index[ch_as_byte] + 1);
            // Update the character's last seen index
            last_index[ch_as_byte] = end as i32;
            // Calculate current window length
            max_len = max_len.max((end as i32 - start + 1));
        }

        max_len
    }
}