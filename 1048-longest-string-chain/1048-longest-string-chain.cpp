class Solution {
public:
    bool match(string a, string b) {
        if (b.size() != a.size() + 1)
            return false;

        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;
                if (j - i > 1)   
                    return false;
            }
        }

        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n =words.size();
        vector<int>ans(n,1);
        sort(words.begin(),words.end(),[](string a, string b){
            return a.size()<b.size();
        });
        for(int i=n-1;i>=0;i--){
            string a = words[i];
            int m = a.size();
            for(int j=i+1;j<n;j++){
                string b = words[j];
                if (b.size() == m)continue;
                if(b.size()>m+1)break;
                if(match(a,b)){
                    ans[i] = max(ans[i],ans[j]+1);
                }
            }
        }
        return *max_element(ans.begin(),ans.end());
    }
};