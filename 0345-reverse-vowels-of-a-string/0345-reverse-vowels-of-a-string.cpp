class Solution {
public:
    string reverseVowels(string s) {
        vector<char>v;
        for(auto x:s){
            if(x=='A' || x=='E' || x=='I' || x=='O' || x=='U' || x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
                v.push_back(x);
            }
        }
        int j=v.size()-1;
        for(int i=0;i<s.size();i++){
            char x=s[i];
              if(x=='A' || x=='E' || x=='I' || x=='O' || x=='U' || x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
                s[i] =v[j];
                j--;
            }
        }
        return s;
    }
};