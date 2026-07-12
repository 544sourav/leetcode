class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long ans = 0;
        int even = 1; // empty prefix
        int odd = 0;
        int sum = 0;

        for (int x : arr) {
            sum += x;

            if (sum % 2 == 0) {
                ans += odd;
                even++;
            } else {
                ans += even;
                odd++;
            }

            ans %= MOD;
        }

        return ans;
    }
};