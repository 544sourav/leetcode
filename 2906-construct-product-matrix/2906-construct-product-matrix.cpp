class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int size = m * n;
        const int MOD = 12345;

        vector<int> pre(size), suf(size);

  
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int idx = i * n + j;

                if(idx == 0) pre[idx] = grid[i][j] % MOD;
                else pre[idx] = (1LL * pre[idx - 1] * grid[i][j]) % MOD;
            }
        }

     
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int idx = i * n + j;

                if(idx == size - 1) suf[idx] = grid[i][j] % MOD;
                else suf[idx] = (1LL * suf[idx + 1] * grid[i][j]) % MOD;
            }
        }

        vector<int> ans(size);

        for(int i = 0; i < size; i++){
            long long left = (i == 0) ? 1 : pre[i - 1];
            long long right = (i == size - 1) ? 1 : suf[i + 1];

            ans[i] = (left * right) % MOD;
        }
        // for(auto x:pre)cout<<x<<" ";
        // cout<<endl;
        // for(auto x:suf)cout<<x<<" ";
        // cout<<endl;
        // for(auto x:ans)cout<<x<<" ";
    

    

        vector<vector<int>> res(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int idx = i * n + j;
                res[i][j] = ans[idx];
            }
        }

        return res;
    }
};