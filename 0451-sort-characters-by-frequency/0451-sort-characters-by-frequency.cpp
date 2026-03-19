class Solution {
public:
    string frequencySort(string s) {
        vector<int> fq(256, 0);

        for (char ch : s) {
            fq[ch]++;
        }

        vector<pair<int, char>> so;
        for (int i = 0; i < 256; i++) {
            if (fq[i] > 0)
                so.push_back({fq[i], (char)i});
        }

        sort(so.begin(), so.end(), greater<>());

        string ans = "";
        for (auto &[freq, ch] : so) {
            ans.append(freq, ch);
        }

        return ans;
    }
};
