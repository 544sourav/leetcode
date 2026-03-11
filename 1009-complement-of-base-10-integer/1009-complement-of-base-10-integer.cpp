class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        string s = bitset<32>(n).to_string();
        string r="";
        int i=0;
        while(s[i]=='0'){
            i++;
        }
        for(i;i<s.size();i++){
            if(s[i]=='1')r+='0';
            else r+='1';
        }
     
        int ans =0;
        int  j =r.size()-1;
        for(int i=0;i<r.size();i++){

            ans += (r[i]-'0')*(1<<j);
            j--;
        }
        return ans;

    }
};