impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut rows = [0; 9];
        let mut cols = [0; 9];
        let mut boxes = [0; 9];

        for i in 0..9 {
            for j in 0..9 {
                if board[i][j] != '.' {
                    let mask = 1 << (board[i][j] as usize - '1' as usize);
                    let box_index = (i / 3) * 3 + j / 3;

                    if (rows[i] & mask) != 0
                        || (cols[j] & mask) != 0
                        || (boxes[box_index] & mask) != 0
                    {
                        return false;
                    }

                    rows[i] |= mask;
                    cols[j] |= mask;
                    boxes[box_index] |= mask;
                }
            }
        }

        true
    }
}
