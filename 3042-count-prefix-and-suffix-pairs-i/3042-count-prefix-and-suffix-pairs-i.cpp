class Solution {
public:
    bool isPrefixAndSuffix(string a, string b) {
        if (a.size() > b.size()) return false;

        int n = a.size();

        string pre = b.substr(0, n);
        string suf = b.substr(b.size() - n);

        return (a == pre && a == suf);
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};