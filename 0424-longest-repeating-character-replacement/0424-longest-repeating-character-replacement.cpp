class Solution {
public:
    int characterReplacement(string s, int k) {
        int n  = s.size();
        int left =0;
        vector<int>mp(26,0);
        int ans =0;
        int maxfre=0;
        for(int right =0;right<n;right++){
            mp[s[right]-'A']++;
            maxfre = max(maxfre, mp[s[right]-'A']);
             while ((right - left + 1) - maxfre > k) {
                mp[s[left] - 'A']--;
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};