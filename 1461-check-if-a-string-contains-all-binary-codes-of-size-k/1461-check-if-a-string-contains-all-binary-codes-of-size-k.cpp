class Solution {
public:
    unordered_map<string,int>mp;
    void allstring(int k,string cur){
        if(cur.size()==k){
            mp[cur] =1;
            return;
        }
        for(int i=0;i<=1;i++){
            allstring(k,cur+to_string(i));
        }
    } 
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        for(int i = 0; i + k <= s.size(); i++) {
            st.insert(s.substr(i, k));
        }
        return st.size() == (1 << k);
    }
};