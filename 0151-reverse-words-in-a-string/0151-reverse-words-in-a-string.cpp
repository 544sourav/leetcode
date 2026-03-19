class Solution {
public:
    string reverseWords(string s) {
        // vector<string> v;
        // string temp = "";
        
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == ' ') {
        //         if (!temp.empty()) {
        //             v.push_back(temp);
        //             temp = "";
        //         }
        //     } else {
        //         temp += s[i];
        //     }
        // }
        // if (!temp.empty()) {
        //     v.push_back(temp);
        // }
        
        // string ans = "";
        // for (int i = v.size() - 1; i >= 0; i--) {
        //     ans += v[i];
        //     if (i != 0) ans += " ";
        // }
        stringstream ss(s);
        string temp;
        vector<string> a;
        string ans ="";
        while(ss>>temp)a.push_back(temp);
        reverse(a.begin(),a.end());
        for(auto x:a){
            ans+=x;
            ans+=" ";
        }
        ans.pop_back();
         return ans;
    }
};
