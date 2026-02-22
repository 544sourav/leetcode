class Solution {
public:
    void solve(vector<int>& nums,set<vector<int>>& ans,vector<int> &cur, int idx){
        if(idx==nums.size()){
            ans.insert(cur);
            return;
        }
        cur.push_back(nums[idx]);
        solve(nums,ans,cur,idx+1);
        cur.pop_back();
        solve(nums,ans,cur,idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end()); 
    set<vector<int>> ans;
    vector<int> cur;
    solve(nums, ans, cur, 0);
    vector<vector<int>> res(ans.begin(), ans.end());
    return res;
}

};