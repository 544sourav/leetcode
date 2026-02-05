class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0]++;
        int sum =0;
        int res =0;
        for(int x:nums){
            sum  += x;
            if(mp.count(sum-goal)){
                res += mp[sum-goal];
            }
            mp[sum]++;
        }
        return res;
    }
};