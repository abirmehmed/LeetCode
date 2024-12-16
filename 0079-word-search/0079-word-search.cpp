class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Loop through each cell in the grid
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                // Start searching from this cell if it matches the first letter
                if (board[row][col] == word[0] && dfs(board, word, row, col, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int row, int col, int index) {
        // Base case: if we have matched all characters
        if (index == word.size()) return true;

        // Check boundaries and if current cell matches
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || 
            board[row][col] != word[index]) {
            return false;
        }

        // Mark the cell as visited by using a special character
        char temp = board[row][col];
        board[row][col] = '#'; // Mark as visited

        // Explore all four directions: down, up, right, left
        bool found = dfs(board, word, row + 1, col, index + 1) ||
                     dfs(board, word, row - 1, col, index + 1) ||
                     dfs(board, word, row, col + 1, index + 1) ||
                     dfs(board, word, row, col - 1, index + 1);

        // Restore the original value after exploring
        board[row][col] = temp;

        return found;
    }
};
