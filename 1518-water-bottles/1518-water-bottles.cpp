class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int rem =0;
        while(numBottles>0){
            int temp = numBottles;
            temp/=numExchange;
            if(temp==0)break;
            total += temp;
            rem = numBottles%numExchange;
            numBottles=temp+rem;
            rem=0;
        }
        return total;
    }
};