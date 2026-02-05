class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; 
        int prefix = 0;
        int cnt = 0;

        for (int x : nums) {
            prefix += x;
            int mod = prefix % k;
            if (mod < 0) mod += k;  

            if (mp.count(mod)) {
                cnt += mp[mod];
            }

            mp[mod]++;
        }

        return cnt;
    }
};
