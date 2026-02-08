class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;

        int curMax = 0, maxKadane = INT_MIN;
        int curMin = 0, minKadane = INT_MAX;

        for (int x : nums) {
            curMax = max(x, curMax + x);
            maxKadane = max(maxKadane, curMax);

            curMin = min(x, curMin + x);
            minKadane = min(minKadane, curMin);

            totalSum += x;
        }

        if (maxKadane < 0) return maxKadane;

        return max(maxKadane, totalSum - minKadane);
    }
};
