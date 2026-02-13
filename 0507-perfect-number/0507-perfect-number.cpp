class Solution {
public:

    bool checkPerfectNumber(int num) {
           int ans =0;

        //    int temp=num;
           for(int i=1;i<=num-i;i++){
            if(num%i==0)ans+=i;
           }
           return ans ==num;
    }
};