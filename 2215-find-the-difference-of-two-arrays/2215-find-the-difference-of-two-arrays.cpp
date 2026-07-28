class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        unordered_map<int,int>mp1;
        vector<vector<int>>ans(2);
        for(auto x:nums2){
            mp[x]++;
        }
        for(auto x:nums1){
            if(mp.find(x)==mp.end()){
                ans[0].push_back(x);
                mp[x]++;
            }
        }

        for(auto x:nums1){
            mp1[x]++;
        }
        for(auto x:nums2){
            if(mp1.find(x)==mp1.end()){
                ans[1].push_back(x);
                mp1[x]++;
            }
        }
        return ans;
        
    }
};