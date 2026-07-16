class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        vector<pair<int,int>> p;
        for(auto[x,y]:mp){
            p.push_back({y,x});
        }
        sort(p.begin(),p.end(),[](auto &a, auto &b ){
            if(a.first==b.first){
                return a.second >b.second;
            }
            return a.first <b.first;
        });
        vector<int>ans;
        for(auto [x,y]:p){
            for(int i =0;i<x;i++){
                ans.push_back(y);
            }
        }
        return ans;
    }
};