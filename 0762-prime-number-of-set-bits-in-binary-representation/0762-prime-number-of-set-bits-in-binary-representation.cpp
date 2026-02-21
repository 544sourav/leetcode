class Solution {
public:
    bool helper(string &s){
        int no1 =0;
        for(auto x:s){
            if(x=='1')no1++;
        }
        if(no1<=1)return false;
        for(int i=2;i*i<=no1;i++){
            if(no1%i==0)return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count =0;
        for(int i = left; i<=right;i++){
            string s = bitset<32>(i).to_string();
            if(helper(s)){
                count++;
            }
        }
        return count;
    }
};