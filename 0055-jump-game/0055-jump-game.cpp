class Solution {
public:
    vector<int> dp;

    bool solve(vector<int>& nums, int idx) {
        if (idx >= nums.size() - 1)
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        for (int jump = 1; jump <= nums[idx]; jump++) {
            if (solve(nums, idx + jump))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        return solve(nums, 0);
    }
};