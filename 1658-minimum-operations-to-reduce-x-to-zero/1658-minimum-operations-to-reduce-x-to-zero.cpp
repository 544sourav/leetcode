class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0, n = nums.size();
        for (int num : nums) target += num;
        target -= x;
        
        if (target == 0) return n;
        
        int maxlen = 0, cur = 0, left = 0;
        
        for (int right = 0; right < n; ++right) {
            cur += nums[right];
            while (left <= right && cur > target) {
                cur -= nums[left];
                left++;
            }
            if (cur == target) {
                maxlen = max(maxlen, right - left + 1);
            }
        }
        
        return maxlen ? n - maxlen : -1;
    }
};