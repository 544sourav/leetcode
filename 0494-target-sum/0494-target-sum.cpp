class Solution {
public:
    int solve(vector<int>& nums, int target, int sum, int i,
              vector<vector<int>>& dp, int offset) {

        if(i == nums.size()) {
            return sum == target;
        }

        if(dp[i][sum + offset] != -1)
            return dp[i][sum + offset];

        int add = solve(nums, target, sum + nums[i],
                        i + 1, dp, offset);

        int subtract = solve(nums, target, sum - nums[i],
                             i + 1, dp, offset);

        return dp[i][sum + offset] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > total)
            return 0;

        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));

        return solve(nums, target, 0, 0, dp, total);
    }
};