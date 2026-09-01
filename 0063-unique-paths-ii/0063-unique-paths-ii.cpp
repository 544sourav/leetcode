class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> v(m, vector<int>(n, 0));


        if (obstacleGrid[0][0] == 1)
            return 0;

        v[0][0] = 1;

        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0)
                v[i][0] = v[i-1][0];
        }

        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0)
                v[0][j] = v[0][j-1];
        }


        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                if (obstacleGrid[i][j] == 1)
                    v[i][j] = 0;
                else
                    v[i][j] = v[i-1][j] + v[i][j-1];
            }
        }

        return v[m-1][n-1];
    }
};