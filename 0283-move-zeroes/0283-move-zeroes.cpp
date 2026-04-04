class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
         int index = 0;  
       
        // // for (int i = 0; i < n; i++) {
        // //     if (nums[i] != 0) {
        // //         nums[index++] = nums[i];
        // //     }
        // // }

        // // while (index < n) {
        // //     nums[index++] = 0;
        // // }
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         for(int j=i;j<n-1;j++){
        //             swap(nums[j],nums[j+1]);
        //         }
        //     }
        // }

        for(int i =0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[index++]);
            }
        }

    }

};
