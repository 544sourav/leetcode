class Solution {
public:

    long long MOD = 1e9 + 7;

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long tot = 0;
        for (auto x : arr) tot += x;

        
        long long sum = 0, best = 0;
        for (int i = 0; i < n; i++) {
            sum = max((long long)arr[i], sum + arr[i]);
            best = max(best, sum);
        }
        long long ans = best;

 
        long long prefix = 0, maxPrefix = 0;
        for (int i = 0; i < n; i++) {
            prefix += arr[i];
            maxPrefix = max(maxPrefix, prefix);
        }

        long long suffix = 0, maxSuffix = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffix += arr[i];
            maxSuffix = max(maxSuffix, suffix);
        }

        if (k >= 2) {
            ans = max(ans, maxSuffix + maxPrefix);
            ans = max(ans, maxSuffix + tot * (k - 2) + maxPrefix);
        }

        return ans % MOD;
    }
};