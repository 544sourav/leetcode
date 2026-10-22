class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo =0;
        int hi = nums.size()-1;
        int mid;
        if(nums.size()==1){
            return nums[0];
        }
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if( mid > 0 && nums[mid] == nums[mid-1]){
                if((mid-lo+1)%2==0){
                    lo = mid+1;
                }
                else{
                    hi = mid-2;
                }
            }
            else if(mid < nums.size() - 1 && nums[mid]==nums[mid+1]){
                if((hi+1-mid )%2 !=0){
                    lo = mid+2;
                }
                else{
                    hi=mid-1;
                }
            }
            else{
                return nums[mid];
            }
            
        }
        return nums[lo];
    }
};