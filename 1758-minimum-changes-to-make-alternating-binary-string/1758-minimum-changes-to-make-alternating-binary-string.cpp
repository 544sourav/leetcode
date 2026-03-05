class Solution {
public:
    int minOperations(string s) {
        int cnt1=0;
        int cnt0 =0;
        char cur='0';
        for(auto x:s){
            if(x!=cur)cnt0++;
            cur =  cur == '0'?'1':'0';
        }
        cur = '1';
        for(auto x:s){
            if(x!=cur)cnt1++;
           cur =  cur == '0'? '1':'0';
            
        }
        return min(cnt1,cnt0);
    }
};