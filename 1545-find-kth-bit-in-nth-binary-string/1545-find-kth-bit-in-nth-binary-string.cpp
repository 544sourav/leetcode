class Solution {
public:
    string invert(string s ){
        for(int i =0;i<s.size();i++){
            if(s[i]=='1'){
                s[i]='0';
            }
            else{
                s[i]='1';
            }
        }
        return s;
    }
    char findKthBit(int n, int k) {
        
        if(k==1) return '0';
        string s = "0";
        for(int i =0;i<n-1;i++){
            string in = invert(s);
            reverse(in.begin(),in.end());
            s= s+'1'+in;
            //cout<<s<<endl;
        }
        
        
        return s[k-1];
    }
};