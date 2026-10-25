class Solution {
public:
    int numberOfSubstrings(string s) {
        long long n = s.size();
        long long total = n*(n+1)/2;
        int sub=0;
        int v[3]={0};
        int i=0;
        for(int j =0;j<n;j++){
            v[s[j]-'a']++;
            while(v[0]!=0 && v[1]!=0 && v[2]!=0){
                v[s[i]-'a']--;
                i++;
            }
            sub+=j-i+1;
        }
        return total-sub;
    }
};