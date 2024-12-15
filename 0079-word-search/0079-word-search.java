class Solution {
    public boolean exist(char[][] board, String word) {
        if (board == null || board.length == 0 || word == null || word.length() == 0) {
            return false;
        }

        int rows = board.length;
        int cols = board[0].length;

        // Iterate through each cell in the grid
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Start searching from each cell
                if (backtrack(board, word, row, col, 0)) {
                    return true; // Word found
                }
            }
        }
        return false; // Word not found
    }

    private boolean backtrack(char[][] board, String word, int row, int col, int index) {
        // Base case: if we have matched all characters in the word
        if (index == word.length()) {
            return true;
        }

        // Check boundaries and if the current cell matches the current character in the word
        if (row < 0 || row >= board.length || col < 0 || col >= board[0].length ||
            board[row][col] != word.charAt(index)) {
            return false;
        }

        // Mark the cell as visited by temporarily changing its value
        char temp = board[row][col];
        board[row][col] = '#'; // Use a special character to mark visited

        // Explore all four directions: up, down, left, right
        boolean found = backtrack(board, word, row + 1, col, index + 1) ||
                        backtrack(board, word, row - 1, col, index + 1) ||
                        backtrack(board, word, row, col + 1, index + 1) ||
                        backtrack(board, word, row, col - 1, index + 1);

        // Restore the original value after exploring
        board[row][col] = temp;

        return found; // Return whether the word was found
    }
}
