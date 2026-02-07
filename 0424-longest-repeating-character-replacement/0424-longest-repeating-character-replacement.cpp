class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(26, 0);
        int i = 0, maxi = 0, count = 0;

        for (int j = 0; j < s.size(); j++) {
            mp[s[j] - 'A']++;
            count = max(count, mp[s[j] - 'A']);

            while (j - i + 1 - count > k) {
                mp[s[i] - 'A']--;
                i++;
            }

            maxi = max(maxi, j - i + 1);
        }
        return maxi;
    }
};
