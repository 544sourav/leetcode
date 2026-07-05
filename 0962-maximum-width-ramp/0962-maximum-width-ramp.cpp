class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int>s;
        int n = nums.size();
        int res =0;
        for(int i=0;i<n;i++){
            if(s.size()==0 || nums[i]< nums[s[s.size()-1]]){
                s.push_back(i);
            }
            else {
                int lo =0, hi = s.size()-1;
                while(lo<hi){
                    int mid  = lo + (hi-lo)/2;
                    if(nums[s[mid]] > nums[i]){
                        lo  =  mid+1;
                    }
                    else hi = mid;
                }
                res  = max(res, i  - s[lo]);
            }
        }
        return res;
    }
};