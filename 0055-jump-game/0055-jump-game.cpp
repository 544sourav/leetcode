class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxs = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>maxs) return false;
            maxs = max(maxs,i+nums[i]);
            // if(maxs>=n-1) return true;
        }
        return true;
    }
};