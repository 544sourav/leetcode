class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi =0;
        int low =prices[0];
        for(auto x:prices){
            low  = min(low,x);
            maxi = max(maxi,x-low);
        }
        return maxi;
    }
};