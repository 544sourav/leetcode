class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans =0;
        int curodd =0;
        for(auto num:nums){
            if(num%2==1)curodd++;
            if(curodd>=k){
                int tg = curodd-k;
                if(mp.find(tg)!=mp.end()){
                    ans += mp[tg];
                }
            }
            mp[curodd]++;
        }
        return ans;
    }
};