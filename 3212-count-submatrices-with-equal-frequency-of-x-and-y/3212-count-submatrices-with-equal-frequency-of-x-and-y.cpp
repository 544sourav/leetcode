class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        vector<vector<pair<int,int>>> dp(m+1,vector<pair<int,int>>(n+1,{0,0}));
        int ans =0;
        bool isy = false;
        bool isx = false;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(grid[i-1][j-1]=='X'){
                    isx=true;
                    int x = dp[i][j-1].first+dp[i-1][j].first-dp[i-1][j-1].first+1;
                    int y = dp[i][j-1].second+dp[i-1][j].second-dp[i-1][j-1].second;
                    dp[i][j]={x,y};
                }
                else if(grid[i-1][j-1]=='Y'){
                    isy=true;
                    int x = dp[i][j-1].first+dp[i-1][j].first-dp[i-1][j-1].first;
                    int y = dp[i][j-1].second+dp[i-1][j].second-dp[i-1][j-1].second+1;
                    dp[i][j]={x,y};
                }
                else {
                    int x = dp[i][j-1].first+dp[i-1][j].first-dp[i-1][j-1].first;
                    int y = dp[i][j-1].second+dp[i-1][j].second-dp[i-1][j-1].second;
                    dp[i][j]={x,y};
                }
            }
        }
        if(!isy && !isx)return 0;
       
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
               
            if(dp[i][j].first==dp[i][j].second &&dp[i][j].first!=0 )ans++;
            }
        }
        return ans;
    }
};