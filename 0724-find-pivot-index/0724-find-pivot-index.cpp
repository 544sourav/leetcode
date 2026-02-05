class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        int val  =nums[n-1];
        for(int i=0;i<n;i++){
            if(i==0 && (val-nums[i])==0 )return i;
            // if(i==n-2 && nums[i]==0)return n-2;
            else if( i!=0 && nums[i-1] ==val-nums[i])return i;
            
        }
        return -1;
    }
};