class Solution {
public:
    
    int solve(int idx, int k, vector<vector<int>>& events, vector<vector<int>>& dp){
        if(idx >= events.size() || k == 0) return 0;

        if(dp[idx][k] != -1) return dp[idx][k];

        int notTake = solve(idx + 1, k, events, dp);
        // next non overlaping  event
        int nextIdx = upper_bound(events.begin(), events.end(), events[idx][1],
            [](int endTime, const vector<int>& event){
                return endTime < event[0];
            }) - events.begin();

        int take = events[idx][2] + solve(nextIdx, k - 1, events, dp);

        return dp[idx][k] = max(take, notTake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        
        sort(events.begin(), events.end()); 
        
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        return solve(0, k, events, dp);
    }
};