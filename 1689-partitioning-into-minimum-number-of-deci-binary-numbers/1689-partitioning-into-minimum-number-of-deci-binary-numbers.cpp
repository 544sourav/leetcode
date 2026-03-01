class Solution {
public:
    int minPartitions(string n) {
        int maxi = INT_MIN;
        for(auto x:n){
            maxi = max(maxi , x-'0');
        }
        return maxi;
    }
};