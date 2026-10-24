class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        for(int i=1;i<n;i++){
            cardPoints[i]+= cardPoints[i-1];
        }
        int total =cardPoints[n-1];
        int ws = n-k;
        if (ws == 0) return total;

        int maxi =total - cardPoints[ws-1];
        for(int i=ws;i<n;i++){
            maxi = max(maxi , total - (cardPoints[i]- cardPoints[i-ws]));
        }
        return maxi;
    }
};