class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi =0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(i==0)sum+=nums[i];
            else if(nums[i]>nums[i-1])sum+=nums[i];
            else {
                maxi = max(maxi,sum);
                sum=nums[i];
            }
        }
        maxi = max(maxi,sum);
        return maxi;
    }
};