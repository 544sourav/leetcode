class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>temp  = nums;
        sort(temp.begin(),temp.end());
        int s = -1;
        int e =-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=temp[i]){
                if(s==-1) s = i;
                e=i;
            }
        }
        if(s==-1 && e==-1)return 0;
        return e-s+1;
    }
};