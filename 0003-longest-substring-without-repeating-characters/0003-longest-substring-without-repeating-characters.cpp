class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        unordered_map<char,int>mp;
        int i=0;
        mp[s[i]]++;
        int maxlen=1;
        for(int j=1;j<s.size();j++){
            mp[s[j]]++;
            while(mp.size()!=j-i+1){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            maxlen =max(maxlen,j-i+1);
        }
        return maxlen;
    }
};