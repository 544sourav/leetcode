class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int i = 0;
        int maxi = 0;

        for (int j = 0; j < s.size(); j++) {

            while (mp.count(s[j]) > 0) {
                mp[s[i]]--;
                
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }

                i++;
            }

            mp[s[j]]++;

            maxi = max(maxi, j - i + 1);
        }

        return maxi;
    }
};