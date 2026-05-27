class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro =1;
        int zero = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }
            else pro *=nums[i];
        }
        if(zero>=2){
            for(int i=0;i<n;i++){
                nums[i]=0;
            }
        }
        else if(zero==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0)nums[i]=pro;
                else nums[i]=0;
            }
        }
        else {
            for(int i=0;i<n;i++){
                nums[i] = pro/nums[i];
            }
        }
        return nums;
    }
};