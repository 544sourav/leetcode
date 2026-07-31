class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        int n = s.size();

       
        for(int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }

        vector<int> last(n);
        for(int i = 0; i < n; i++) {
            last[i] = mp[s[i]];
        }

        vector<int> ans;
        int start = 0;
        int end = 0;

        for(int i = 0; i < n; i++) {
            end = max(end, last[i]);

            if(i == end) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};