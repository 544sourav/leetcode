class Solution {
public:
    int subarray(vector<int>&nums,int k){
        int i =0;
        int odd =0;
        int cnt=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]%2==1)odd++;
            while(odd>k){
                if(nums[i]%2==1)odd--;
                i++;
            }
            cnt += j-i+1;            
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return subarray(nums,k)-subarray(nums,k-1);
    }
};