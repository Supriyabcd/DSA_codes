#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void solve(int col, int n, vector<vector<string>>& ans, vector<string>& board, 
               vector<int>& leftRow, vector<int>& upperDiag, vector<int>& lowerDiag) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && upperDiag[n - 1 + col - row] == 0 && lowerDiag[row + col] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiag[n - 1 + col - row] = 1; 
                lowerDiag[row + col] = 1;
                
                solve(col + 1, n, ans, board, leftRow, upperDiag, lowerDiag);
                
                board[row][col] = '.';  // Backtrack
                leftRow[row] = 0;
                upperDiag[n - 1 + col - row] = 0; 
                lowerDiag[row + col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));  // Initialize board with empty positions
        vector<int> leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
        solve(0, n, ans, board, leftRow, upperDiag, lowerDiag);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    Solution solution;
    vector<vector<string>> result = solution.solveNQueens(n);

    cout << "Solutions for " << n << "-Queens Problem:\n";
    for (const auto& board : result) {
        for (const string& row : board) {
            cout << row << "\n";
        }
        cout << "\n";  // Separate different solutions
    }

    return 0;
}
