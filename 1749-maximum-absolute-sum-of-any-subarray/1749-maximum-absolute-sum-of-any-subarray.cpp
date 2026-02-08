class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sumpve = 0;
        int sumnve= 0;
        int maxi = INT_MIN;
        for(auto x:nums){
            sumpve =max(x,sumpve+x);
            sumnve = max(-1*x,sumnve+(-1*x));
            maxi = max({maxi,sumpve,sumnve}); 
        }
        return maxi;
    }
};