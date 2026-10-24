class Solution {
public:
    int calculateSplits(vector<int>& nums,int mini){
        int totalSplits =1;
        int sum =0;
        for(auto x:nums){
            
            if(sum+x>mini){
                totalSplits++;
                sum=x;
            }
            else{
                sum+=x;
            }
        }
        return totalSplits;
    }
    int splitArray(vector<int>& nums, int k) {
        int lo =*max_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(),nums.end(),0);
        
        while(lo<hi){
            int mid = lo +(hi-lo)/2;
            int totalSplits = calculateSplits(nums,mid);
            if(totalSplits>k){
                lo=mid+1;
            }
            else hi =mid;
        }
        return lo;

    }
};