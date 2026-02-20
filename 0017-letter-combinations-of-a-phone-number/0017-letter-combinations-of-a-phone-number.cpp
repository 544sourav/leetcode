class Solution {
public:
    unordered_map<char, string> mp {
        {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
        {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
    };

    void solve(const string& digits, int idx, vector<string>& ans, string& cur) {
        if (idx == digits.size()) {
            ans.push_back(cur);
            return;
        }

        for (char c : mp[digits[idx]]) {
            cur.push_back(c);
            solve(digits, idx + 1, ans, cur);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans;
        string cur;
        solve(digits, 0, ans, cur);
        return ans;
    }
};
