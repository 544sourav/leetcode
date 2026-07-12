class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd=0;
        int even =0;
        int sum =0;
        long long  total =0;
        for(auto x:arr){
            sum +=x;
            if(sum%2 ==0){
                even++;
                total += odd;
            }
            else{
                odd++;
                total += even +1;
            }
        }
        int mod = 1e9 +7;
        return total% mod;
    }
};