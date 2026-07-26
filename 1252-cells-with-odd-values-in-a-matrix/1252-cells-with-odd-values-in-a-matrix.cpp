class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> g(m, vector<int>(n, 0));

        for (auto &v : indices) {
            int x = v[0]; 
            int y = v[1];

            
            for (int i = 0; i < n; i++) {
                g[x][i]++;
            }

            
            for (int i = 0; i < m; i++) {
                g[i][y]++;
            }
        }

        int odd = 0;
        for (auto &row : g) {
            for (int val : row) {
                if (val % 2) odd++;
            }
        }

        return odd;
    }
};