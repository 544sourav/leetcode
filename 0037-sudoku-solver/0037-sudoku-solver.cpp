class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, char k) {
        for (int x = 0; x < 9; x++) {
            if (board[i][x] == k) return false; 
            if (board[x][j] == k) return false;  
        }

        int startRow = (i / 3) * 3;
        int startCol = (j / 3) * 3;
        for (int x = startRow; x < startRow + 3; x++) {
            for (int y = startCol; y < startCol + 3; y++) {
                if (board[x][y] == k) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;                
        if (j == 9) return solve(board, i + 1, 0); 
        if (board[i][j] != '.') return solve(board, i, j + 1);

        for (char ch = '1'; ch <= '9'; ch++) {
            if (check(board, i, j, ch)) {
                board[i][j] = ch;
                if (solve(board, i, j + 1)) return true;
                board[i][j] = '.'; 
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
