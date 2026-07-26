class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int m = nums.size();
        int ans = n;

        for (int i = 0; i < m; i++) {
            int idx = lower_bound(nums.begin(), nums.end(), nums[i] + n) - nums.begin();
            int cnt = idx - i;
            ans = min(ans, n - cnt);
        }

        return ans;
    }
};