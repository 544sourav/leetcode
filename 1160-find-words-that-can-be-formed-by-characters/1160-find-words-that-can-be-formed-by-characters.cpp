class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mp;
        int ans =0;
        for(auto x:chars){
            mp[x]++;
        }
        for(int i=0;i<words.size();i++){
            string x = words[i];
            unordered_map<char,int>temp;
            for(auto y:x){
                temp[y]++;
            }
            bool flag  =true;
            for(auto [ch,cnt]:temp){
                if(mp.find(ch)==mp.end() || mp[ch]<cnt){
                    flag  = false;
                    break;
                }
            }
            if(flag)ans += x.size();
        }
        return ans;
    }
};