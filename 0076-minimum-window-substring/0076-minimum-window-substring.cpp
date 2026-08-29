class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpt, mps;
        for(char c : t) mpt[c]++;

        int i = 0, j = 0;
        int cnt = 0;
        int n = t.size();
        int start = 0, end = INT_MAX;

        for(int j=0;j<s.size();j++){
            if (mpt.count(s[j])) {
                mps[s[j]]++;
                if (mps[s[j]] <= mpt[s[j]]) cnt++;
            }

            while (cnt == n) {
                if (end == INT_MAX || (j - i + 1) < (end - start + 1)) {
                    start = i;
                    end = j;
                }

                if (mpt.count(s[i])) {
                    mps[s[i]]--;
                    if (mps[s[i]] < mpt[s[i]]) cnt--;
                }
                i++;
            }

        }

        return (end == INT_MAX) ? "" : s.substr(start, end - start + 1);
    }
};
