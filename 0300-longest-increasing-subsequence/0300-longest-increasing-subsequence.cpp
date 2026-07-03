class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        int ans = 1;
        for(int i=n-1;i>=0;i--){
            int maxi =0;
            for(int j=i;j<n;j++){
                if(nums[i]<nums[j]){
                    maxi = max(maxi,dp[j]);
                }
            }
            dp[i] = maxi+1;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};