class Solution {
public:
    void dfs(vector<int>& nums,
             vector<int>& curr,
             vector<bool>& used,
             vector<vector<int>>& ans) {

        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

          
            used[i] = true;
            curr.push_back(nums[i]);

         
            dfs(nums, curr, used, ans);

           
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(nums.size(), false);

        dfs(nums, curr, used, ans);
        return ans;
    }
};
