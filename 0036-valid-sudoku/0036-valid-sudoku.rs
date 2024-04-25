impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        // Check rows
        for row in 0..9 {
            if !Self::check_duplicates(&board[row]) {
                return false;
            }
        }

        // Check columns
        for col in 0..9 {
            let mut col_chars = Vec::new();
            for row in 0..9 {
                col_chars.push(board[row][col]);
            }
            if !Self::check_duplicates(&col_chars) {
                return false;
            }
        }

        // Check 3x3 sub-boxes
        for i in 0..9 {
            let mut sub_box_chars = Vec::new();
            for row in (i / 3 * 3)..(i / 3 * 3 + 3) {
                for col in (i % 3 * 3)..(i % 3 * 3 + 3) {
                    sub_box_chars.push(board[row][col]);
                }
            }
            if !Self::check_duplicates(&sub_box_chars) {
                return false;
            }
        }

        true
    }

    fn check_duplicates(chars: &[char]) -> bool {
        let mut seen = [false; 10];
        for &c in chars {
            if c != '.' {
                let idx = c as usize - '1' as usize + 1;
                if seen[idx] {
                    return false;
                }
                seen[idx] = true;
            }
        }
        true
    }
}
