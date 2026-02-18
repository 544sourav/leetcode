class Solution {
public:
    string to_binary(int n){
        string ans ="";
        while(n>0){
            ans += to_string(n%2);
            n/=2;
        }
        return ans;
    }
    bool hasAlternatingBits(int n) {
        string binary = to_binary(n);
        for(int i=1;i<binary.size();i++){
            if(binary[i]==binary[i-1])return false;
        }
        return true;
    }
};