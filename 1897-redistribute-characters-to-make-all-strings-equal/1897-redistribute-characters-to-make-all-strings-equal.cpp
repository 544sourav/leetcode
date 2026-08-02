class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>mp;
        for(auto w:words){
            for(auto ch:w){
                mp[ch]++;
            }
        }
        int n = words.size();
        for(auto [x,y]:mp){
            if(y%n!=0)return false;
        }
        return true;
    }
};