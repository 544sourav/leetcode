class Solution {
public:
    vector<string>v;
    vector<char> l {'a', 'b', 'c'};
    void backtrack(int n, int k, string &s) {
       
        if (s.size() == n) {
            k--;
            v.push_back(s);
            return;
        }
        if (k==0) {
            return;
        }
        for (int i = 0; i < 3; i++) {
            int g = s.size();
            if (g == 0 || s[g - 1] != l[i]) {  
                s += l[i];
                backtrack(n, k, s);
                s.erase(s.length() - 1);
            }
        }
        return;
    }

    string getHappyString(int n, int k) {
        string s;
        backtrack(n, k, s);
        if (k > v.size()) return "";  
        return v[k - 1];  
    }
};