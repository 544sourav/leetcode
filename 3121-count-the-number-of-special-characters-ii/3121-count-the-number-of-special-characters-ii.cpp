class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mp;
        unordered_map<char,int>lmp;
        int cnt=0;
        for(int i=0;i<word.size();i++){
            char ch  = word[i];
            if(isupper(ch) && mp.find(ch)==mp.end()){
                mp[ch]=i;
            }
            else if(islower(ch)){
                lmp[ch]=i;
            }
        }
        for(auto [x,y]:lmp){
            char ch = toupper(x);
            if(mp.find(ch)!=mp.end()&& mp[ch]>y)cnt++;
        }
        return cnt;
        
        
    }
};