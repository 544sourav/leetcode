class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(auto x:s){
            mp[x]++;
        }
        char ans;
        for(auto x:t){
            if(mp.find(x)==mp.end())ans=x;
            mp[x]--;
            if(mp[x]==0)mp.erase(x);
        }
        return ans;

    }
};