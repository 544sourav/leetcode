class Solution {
public:
    void solve(vector<int>& c, int t, vector<vector<int>>& ans, vector<int>& cur, int sum, int idx) {
        if (sum == t) {
            ans.push_back(cur);
            return;
        }
        if (idx >= c.size() || sum > t) return;

        
        cur.push_back(c[idx]);
        solve(c, t, ans, cur, sum + c[idx], idx);
        cur.pop_back();
        solve(c, t, ans, cur, sum, idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> cur;
        solve(c, t, ans, cur, 0, 0);
        return ans;
    }
};
