class Solution {
public:
    vector<vector<int>> dir{{0,1},{1,0},{-1,0},{0,-1}};

    int find(int x, vector<int>& parent) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x], parent);
    }

    void unite(int x, int y, vector<int>& parent, vector<int>& rank, int& count) {
        int px = find(x, parent);
        int py = find(y, parent);

        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        count--;   
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> parent(m * n), rank(m * n, 0);
        int count = 0;

        for (int i = 0; i < m * n; i++) parent[i] = i;

        auto id = [n](int x, int y) {
            return x * n + y;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;

                count++; 
                int cur = id(i, j);

                for (auto& d : dir) {
                    int nx = i + d[0];
                    int ny = j + d[1];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                        grid[nx][ny] == '1') {
                        unite(cur, id(nx, ny), parent, rank, count);
                    }
                }
            }
        }
        return count;
    }
};
