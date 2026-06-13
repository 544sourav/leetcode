class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int cur =0;
        int total = 0;
        for(int i=0;i<nums.size();i++){
            cur +=nums[i];
            int need  = cur -k;
            if(mp.find(need)!=mp.end()){
                total+=mp[need];
            }
            mp[cur]++;
        }
        return total;
    }
};