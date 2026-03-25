class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> hsum(n, 0);  
        vector<long long> vsum(m, 0);

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                hsum[i] += grid[i][j];
                vsum[j] += grid[i][j];
            }
        }

   
        for (int i = 1; i < n; i++) {
            hsum[i] += hsum[i - 1];
        }

        long long total = hsum[n - 1];

       
        for (int i = 0; i < n - 1; i++) {
            if (hsum[i] == total - hsum[i]) {
                return true;
            }
        }

       
        for (int i = 1; i < m; i++) {
            vsum[i] += vsum[i - 1];
        }

        total = vsum[m - 1];

      
        for (int i = 0; i < m - 1; i++) {
            if (vsum[i] == total - vsum[i]) {
                return true;
            }
        }

        return false;
    }
};
