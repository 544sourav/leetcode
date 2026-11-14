class Solution {
public:
    int solve(int k,vector<int>&prices,int n,int i , int buy,vector<vector<vector<int>>>&dp){
        if(i>=n || k==0)return 0;
        if(dp[i][k][buy]!=-1)return dp[i][k][buy];
        if(buy){
            int sell = prices[i]+solve(k-1,prices,n,i+1,0,dp);
            int skip = solve(k,prices,n,i+1,1,dp);
            return dp[i][k][buy] = max(sell,skip);
        }
        else{
            int purchase = -prices[i] + solve(k,prices,n,i+1,1,dp);
            int skip = solve(k,prices,n,i+1,0,dp);
            return dp[i][k][buy] = max(purchase,skip);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(k+1, vector<int>(2, -1))
        );
        return solve(k,prices,n,0,0,dp);
    }
};