class Solution {
public:
    bool check(string rep, string &s){
        int m = rep.size();

        if(s.size() % m != 0) return false;

        for(int i = 0; i < s.size(); i += m){
            if(rep != s.substr(i, m)) return false;
        }

        return true;
    }

    bool repeatedSubstringPattern(string s) {
        for(int i = 1; i < s.size(); i++){
            if(check(s.substr(0, i), s)) return true;
        }

        return false;
    }
};