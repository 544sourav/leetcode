class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001] = {0};

        for (auto &v : trips) {
            int passengers = v[0];
            int start = v[1];
            int end = v[2];

            diff[start] += passengers;
            diff[end]   -= passengers;
        }

        int curr = 0;
        for (int i = 0; i <= 1000; i++) {
            curr += diff[i];
            if (curr > capacity) return false;
        }

        return true;
    }
};
