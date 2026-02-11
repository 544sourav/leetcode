class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        int lo = *max_element(w.begin(), w.end());
        int hi = accumulate(w.begin(), w.end(), 0);

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int days = 1;
            int sum = 0;

            for (int wt : w) {
                if (sum + wt > mid) {
                    days++;
                    sum = wt;
                } else {
                    sum += wt;
                }

                if (days > d) break;
            }

            if (days <= d) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
