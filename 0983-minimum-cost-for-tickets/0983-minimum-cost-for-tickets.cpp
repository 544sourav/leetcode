class Solution {
public:
    vector<vector<int>> dp;

    int recursion(vector<int>& days, int till, int i, vector<int>& costs) {
        if (i >= days.size())
            return 0;

        if (dp[i][till] != -1)
            return dp[i][till];

        if (till >= days[i])
            return dp[i][till] = recursion(days, till, i + 1, costs);

        int oneDay = costs[0] + recursion(days, days[i], i + 1, costs);
        int sevenDay = costs[1] + recursion(days, days[i] + 6, i + 1, costs);
        int thirtyDay = costs[2] + recursion(days, days[i] + 29, i + 1, costs);

        return dp[i][till] = min({oneDay, sevenDay, thirtyDay});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.assign(days.size() + 1, vector<int>(396, -1));
        return recursion(days, 0, 0, costs);
    }
};