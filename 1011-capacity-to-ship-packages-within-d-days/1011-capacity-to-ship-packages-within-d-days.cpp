class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        int lo = *max_element(w.begin(),w.end());
        int hi = accumulate(w.begin(),w.end(),0);
        int ans=-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int sum =0;
            int cnt =0;
            for(auto wt:w){
                if(sum + wt >mid){
                    cnt++;
                    sum = wt;
                }
                else{
                    sum+=wt;
                }
            }
            if(cnt<=d-1){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};