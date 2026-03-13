class Solution {
public:
    bool check(long long mid, int h, vector<int>& w){

        for(int i = 0; i < w.size(); i++){
            long long time = 0;
            int j = 0;

            while(time <= mid){
                j++;
                time += (long long)w[i] * j;

                if(time > mid) break;
                h--;
                if(h <= 0) return true;
            }
        }

        return false;
    }

    long long minNumberOfSeconds(int h, vector<int>& w) {

        long long lo = 1;
        long long hi = 1e18;
        long long ans = hi;

        while(lo <= hi){
            long long mid = lo + (hi - lo) / 2;

            if(check(mid, h, w)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};