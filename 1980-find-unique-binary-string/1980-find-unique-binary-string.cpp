class Solution {
public:
    int n;
    
    bool backtrack(unordered_set<string>& st, string& s) {
        if (s.size() == n) {
            if (st.find(s) == st.end()) { 
                return true;
            }
            return false;
        }

        for (int i = 0; i <= 1; i++) {
            s.push_back(i + '0'); 
            
            if (backtrack(st, s)) return true; 
            
            s.pop_back();  
        }
        return false;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        string s;
        n = nums.size();
        backtrack(st, s);
        return s;
    }
};
