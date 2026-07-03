class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> h(n, vector<int>(m, INT_MAX));
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>pq;
    
        h[0][0] = 0;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [a, i, j] = pq.top();
            pq.pop();
            for (auto [x, y] : dir) {
                int nx = i + x;
                int ny = j + y;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m ) {
                    int absdif = abs(heights[i][j]-heights[nx][ny]);
                    int maxdif  = max(a,absdif);
                    if(h[nx][ny]>maxdif){
                        h[nx][ny]=maxdif;
                        pq.push({maxdif,nx,ny});
                    }

                }
            }

        }
        return h[n-1][m-1];
    }
};