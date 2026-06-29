class Solution {
public:
    bool buddyStrings(string s, string g) {
       int n = s.size();
       int m = g.size();
       if(n!=m)return false;
       vector<int> miss;
       unordered_map<char,int>mp;
       for(int i=0;i<n;i++){
        if(s[i]!=g[i])miss.push_back(i);
        mp[s[i]]++;

       }
       if(miss.size()==0 && mp.size()<s.size()){
            return true;
       }
       if(miss.size()!=2)return false;
       swap(s[miss[0]],s[miss[1]]);
       if(s==g)return true;
       return false;

    }
};