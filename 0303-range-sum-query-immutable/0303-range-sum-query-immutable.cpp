class NumArray {
public:
    vector<int>num;
    NumArray(vector<int>& nums) {

        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i]+nums[i-1];
        }
        num = nums;
    }
    
    int sumRange(int left, int right) {
        if(left >0){
            return num[right]-num[left-1];
        }
        else return num[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */