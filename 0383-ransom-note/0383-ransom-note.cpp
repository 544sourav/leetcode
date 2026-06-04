class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        for(auto c:magazine) {
            mp[c]++;
        }
        bool flag = true;
        for(auto c:ransomNote){
            if(mp.find(c)==mp.end()){
                flag = false;
                break;
            }
            mp[c]--;
            if(mp[c]==0){
                mp.erase(c);
            }
        }
        return flag;
    }
};