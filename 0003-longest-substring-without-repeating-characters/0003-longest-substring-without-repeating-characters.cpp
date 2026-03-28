class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // vector<int>last(256,-1);
        unordered_map<int,int>mp;
        int n = s.size();
        // int start =0;
        int maxi = 0;
        // for(int i=0;i<n;i++){
        //     if(last[s[i]]>=start){
        //         start = last[s[i]]+1;
        //     }
        //     last[s[i]] = i;
        //     maxi = max(maxi,i-start+1);
        // }
        // return maxi;
        int i=0;
        for(int j =0;j<n;j++){
            mp[s[j]]++;
            while(mp.size()<j-i+1){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            maxi =max(maxi,j-i+1);
        }
        return maxi;
    }
};