class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long sum = 0;
        long long maxi = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
            mp[nums[i]]++;
        }

        if (mp.size() == k)
            maxi = sum;

        int i = 0;
        for (int j = k; j < nums.size(); j++) {
            sum += nums[j];
            mp[nums[j]]++;

            sum -= nums[i];
            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
                mp.erase(nums[i]);

            if (mp.size() == k)
                maxi = max(maxi, sum);

            i++;
        }

        return maxi;
    }
};