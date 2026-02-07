class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        for (auto &q : shifts) {
            int val = (q[2] == 1) ? 1 : -1;
            diff[q[0]] += val;
            diff[q[1] + 1] -= val;
        }

        for (int i = 1; i <= n; i++) {
            diff[i] += diff[i - 1];
        }

        for (int i = 0; i < n; i++) {
            int shift = diff[i] % 26;
            // int newchar = (s[i] - 'a' + shift + 26) % 26;
            int newchar = (s[i]-'a' +shift)%26;
            if(newchar<0) newchar += 26;
            s[i] = char('a' + newchar);
        }

        return s;
    }
};
