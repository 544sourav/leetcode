class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi =0;
        int prev=0;
        int cur=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                maxi = max(maxi,prev+cur);
                prev=cur;
                cur=0;
            }
            else cur++;
        }
         maxi = max(maxi,prev+cur);
        return maxi==n?maxi-1:maxi;
    }
};