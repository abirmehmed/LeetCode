func isValidSudoku(board [][]byte) bool {
    var rows, cols, boxes [9]int

    for i := 0; i < 9; i++ {
        for j := 0; j < 9; j++ {
            if board[i][j] != '.' {
                mask := 1 << (board[i][j] - '1')
                boxIndex := (i/3)*3 + j/3

                if rows[i]&mask != 0 || cols[j]&mask != 0 || boxes[boxIndex]&mask != 0 {
                    return false
                }

                rows[i] |= mask
                cols[j] |= mask
                boxes[boxIndex] |= mask
            }
        }
    }

    return true
}
