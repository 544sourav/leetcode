class Solution {
public:
    int subarray(vector<int>&nums,int k){
        int n = nums.size();
        int i =0;
        int j=0;
        unordered_map<int,int>mp;
        int cnt=0;
        for(int j=0;j<n;j++){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            cnt += j-i+1;
         
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarray(nums,k) - subarray(nums,k-1);
        
    }

};