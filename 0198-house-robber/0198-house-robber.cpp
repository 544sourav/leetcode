class Solution {
public:
    vector<int>dp;
    int recursion(vector<int>&nums ,int i){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int take = nums[i]+recursion(nums,i+2);
        int skip = recursion(nums,i+1);
        return dp[i]  = max(take,skip);
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return recursion(nums,0);
    }
};