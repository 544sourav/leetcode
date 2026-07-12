class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int  i=0;
        int cnt0=0;
        int cnt1 =0;
        int ans=0;
        int n =nums.size();
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                cnt0++;
            }
            else cnt1 ++;
            while(cnt0>1  && i<n){
                if(nums[i]==1)cnt1--;
                else cnt0--;
                i++;
            }
            ans = max(cnt1,ans);
        }
        if(ans ==n)ans--;
        return ans;
    }
};