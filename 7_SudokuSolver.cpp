#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {  // Empty cell found
                    for (char c = '1'; c <= '9'; c++) {  // Try numbers 1-9
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;  // Place the number
                            if (solve(board))  // Recursively solve
                                return true;
                            else
                                board[i][j] = '.';  
                        }
                    }
                    return false;  // If no valid number, return false
                }
            }
        }
        return true;  // Solved successfully
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c)  // Check row
                return false;
            if (board[i][col] == c)  // Check column
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + (i % 3)] == c)  // Check 3x3 grid
                return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution solution;
    solution.solveSudoku(board);

    cout << "Solved Sudoku:" << endl;
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
