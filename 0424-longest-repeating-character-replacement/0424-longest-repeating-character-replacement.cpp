class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0;
        int j=0;
        int count =0;
        int maxi = INT_MIN;
        vector<int>mp(26,0);
        while(j<n){
            mp[s[j]-'A']++;
            count = max(count,mp[s[j]-'A']);
            if(j-i+1-count >k){
                mp[s[i]-'A']--;
                i++;
            }
            if(j-i-count <=k){
                maxi = max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
    }
};