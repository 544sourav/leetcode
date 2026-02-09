class Solution {
public:
    
    void solve(vector<int>& c, int t,
           vector<vector<int>>& ans,
           vector<int>& cur,
           int sum, int idx) {

    if (sum == t) {
        ans.push_back(cur);
        return;
    }

    for (int i = idx; i < c.size(); i++) {

        
        if (i > idx && c[i] == c[i - 1]) continue;

        if (sum + c[i] > t) break;

        cur.push_back(c[i]);
        solve(c, t, ans, cur, sum + c[i], i + 1);
        cur.pop_back();
    }
}

    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end());

        vector<vector<int>> ans;
        vector<int> cur;

        solve(c, t, ans, cur, 0, 0);

        
        set<vector<int>> res(ans.begin(), ans.end());

        
        ans.assign(res.begin(), res.end());

        return ans;
    }
};
