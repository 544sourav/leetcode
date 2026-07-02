class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans;
        while( ss >> word){
            reverse(word.begin(),word.end());
            ans +=word;
            ans += " ";
        }
        string finalans(ans.begin(),ans.end()-1);
        return finalans;
    }
};