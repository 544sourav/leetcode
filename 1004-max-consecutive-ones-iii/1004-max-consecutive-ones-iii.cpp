class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // vector<int>store(2,0);
        int maxi =0;
        int cnt0=0;
        int n = nums.size();
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0)cnt0++;
            while(cnt0>k){
                if(nums[i]==0)cnt0--;
                i++;
            }
            maxi = max(maxi,j-i+1);
        }
        return maxi;

    }
};