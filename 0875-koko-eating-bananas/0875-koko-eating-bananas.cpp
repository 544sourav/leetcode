class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        int k = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long cal = 0;
            
            for (int p : piles) {
                cal += (p + mid - 1) / mid; 
            }

            if (cal <= h) {
                k = mid;
                hi = mid - 1; 
            } else {
                lo = mid + 1; 
            }
        }

        return k;
    }
};
