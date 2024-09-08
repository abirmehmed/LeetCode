class Solution {
public:
    int totalNQueens(int n) {
        vector<int> queens(n, -1); // queens[i] will be the column position of the queen in the i-th row
        return solve(queens, 0, n);
    }

private:
    int solve(vector<int>& queens, int row, int n) {
        if (row == n) {
            return 1; // Found a valid solution
        }
        int count = 0;
        for (int col = 0; col < n; ++col) {
            if (isValid(queens, row, col, n)) {
                queens[row] = col;
                count += solve(queens, row + 1, n);
                queens[row] = -1; // Backtrack
            }
        }
        return count;
    }

    bool isValid(vector<int>& queens, int row, int col, int n) {
        for (int i = 0; i < row; ++i) {
            if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
                return false; // Same column or same diagonal
            }
        }
        return true;
    }
};
