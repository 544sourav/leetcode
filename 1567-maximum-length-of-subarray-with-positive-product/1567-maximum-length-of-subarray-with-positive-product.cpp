class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int i=0;
        int neg =0;
        int lastneg =-1;
        int maxi =0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0){
                i=j+1;
                neg =0;
                lastneg =-1;
                continue;
            }
            if(nums[j]<0){
                neg++;
               if(lastneg==-1)  lastneg =j;
            }
            if(neg%2==0){
                maxi = max(j-i+1,maxi);
            }
            else {
                maxi =max(j-lastneg,maxi);
            }
        }
        return maxi;
    }
};