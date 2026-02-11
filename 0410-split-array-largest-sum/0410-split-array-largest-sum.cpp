class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        int lo =  *max_element(arr.begin(),arr.end());
        int hi =accumulate(arr.begin(),arr.end(),0);
        int res = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 1;
            int sum = 0;
            for (int i = 0; i <arr.size(); i++) {
                if (sum + arr[i] > mid) {
                    cnt++;
                    sum = arr[i];
                } else {
                    sum += arr[i];
                }
            }

            if (cnt <= k) {
                res = mid;
                hi = mid - 1; 
            } else {
                lo = mid + 1; 
            }
        }

        return res;
    }
};