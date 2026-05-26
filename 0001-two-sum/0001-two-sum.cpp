class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int,int>mp;
        // for(auto n:nums){
        //     mp[n]++;
        // }
        // for(auto n:nums){
        //     mp[n]--;
        //     int rem = target-n;
        //     if(mp.find(rem)!=mp.end()&& mp[rem]!=0){
        //         return {}
        //     }
        // }
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target)return{i,j};
            }
        }
        return{-1,-1};
    }
};