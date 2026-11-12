class Solution {
public:
    int dp[50001][2];

    int solve(vector<int>& prices, int fee, int i, int buy) {
        if (i == prices.size()) return 0;

        if (dp[i][buy] != -1) return dp[i][buy];

        if (buy) {
            int sell = prices[i] - fee +
                       solve(prices, fee, i + 1, 0);

            int skip = solve(prices, fee, i + 1, 1);

            return dp[i][buy] = max(sell, skip);
        }
        else {
            int purchase = -prices[i] +
                           solve(prices, fee, i + 1, 1);

            int skip = solve(prices, fee, i + 1, 0);

            return dp[i][buy] = max(purchase, skip);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, fee, 0, 0);
    }
};