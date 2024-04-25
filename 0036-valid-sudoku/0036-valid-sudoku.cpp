class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0), cols(9, 0), boxes(9, 0);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int mask = 1 << (board[i][j] - '1');
                    int boxIndex = (i / 3) * 3 + j / 3;

                    if ((rows[i] & mask) != 0
                        || (cols[j] & mask) != 0
                        || (boxes[boxIndex] & mask) != 0) {
                        return false;
                    }

                    rows[i] |= mask;
                    cols[j] |= mask;
                    boxes[boxIndex] |= mask;
                }
            }
        }

        return true;
    }
};
