class Solution {
    public int majorityElement(int[] nums) {
        int cand =0;
        int cnt =1;
        int n = nums.length;
        for(int i=0;i<n;i++){
            if(cnt==0)cnt++;
            if(cnt==1)cand = nums[i];
            
            if(cand==nums[i])cnt++;
            else cnt--;
        }
        return cand;
    }
}