class Solution {
public:
    void solve(vector<int>& cur ,vector<vector<int>> & res,int idx,vector<int>& nums ){
        if(idx == nums.size()){
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[idx]);
        solve(cur,res,idx+1,nums);
        cur.pop_back();
        solve(cur,res,idx+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>cur;
        solve(cur,res,0,nums);
        return res;
    }
};