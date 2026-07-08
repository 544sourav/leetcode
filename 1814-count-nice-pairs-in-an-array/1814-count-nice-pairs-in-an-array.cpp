class Solution {
public:
    int rev(int x) {
        int r = 0;
        while (x) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x - rev(x)]++;
        }

        long long ans = 0;
        const int mod = 1e9 + 7;

        for (auto &[key, cnt] : mp) {
            ans = (ans + 1LL * cnt * (cnt - 1) / 2) % mod;
        }

        return ans;
    }
};