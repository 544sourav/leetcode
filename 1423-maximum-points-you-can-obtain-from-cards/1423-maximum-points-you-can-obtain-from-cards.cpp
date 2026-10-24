class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        for (int i = 1; i < n; i++) {
            cardPoints[i] += cardPoints[i - 1];
        }

        int total = cardPoints[n - 1];
        int ws = n - k;

        if (ws == 0) return total;

        int mini = cardPoints[ws - 1];

        for (int i = ws; i < n; i++) {
            int windowSum = cardPoints[i] - cardPoints[i - ws];
            mini = min(mini, windowSum);
        }

        return total - mini;
    }
};