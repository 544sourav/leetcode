class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int idx, int target, vector<int>& nums) {
        if (target == 0) return true;
        if (idx >= nums.size() || target < 0) return false;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        bool take = solve(idx + 1, target - nums[idx], nums);
        bool notTake = solve(idx + 1, target, nums);

        return dp[idx][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2) return false;

        int target = sum / 2;

        dp.resize(nums.size(), vector<int>(target + 1, -1));

        return solve(0, target, nums);
    }
};