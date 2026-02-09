class Solution {
public:
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    int m, n;

    bool solve(int i, int j, int k, vector<vector<char>>& board, string& word) {
        if(k == word.size()) return true; 

        char temp = board[i][j];
        board[i][j] = '#'; 

        for(auto [x, y] : dir) {
            int ni = i + x;
            int nj = j + y;
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == word[k]) {
                if(solve(ni, nj, k+1, board, word))
                    return true;
            }
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(solve(i, j, 1, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};
