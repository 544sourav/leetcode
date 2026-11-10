class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        queue<pair<int,int>> q;

        vector<pair<int,int>> dir = {
            {0,1}, {1,0}, {-1,0}, {0,-1}
        };
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()) {
            auto [i,j] = q.front();
            q.pop();

            for(auto [x,y] : dir) {
                int ni = i + x;
                int nj = j + y;

                if(ni >= 0 && nj >= 0 && ni < m && nj < n &&
                   dist[ni][nj] == INT_MAX) {

                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni,nj});
                }
            }
        }

        return dist;
    }
};