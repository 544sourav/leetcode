class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cntx=0;
        int x;
        for(auto y:nums){
            if(cntx==0)x=y;
            if(x==y)cntx++;
            else cntx--;
        }
        return x;
    }
};