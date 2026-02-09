class Solution {
public:
    vector<int> nextPermutation(vector<int>&nums){
        int n =nums.size();
        int i = n-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        if(i>=0){
            int j=n-1;
            while(j>=0 && nums[j]<nums[i]){
                j--;
            }
            swap(nums[j],nums[i]);
        }
         reverse(nums.begin()+i+1,nums.end());
         return nums;
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end()); 
    ans.push_back(nums);

    while (true) {
        vector<int> next = nextPermutation(nums);
        if (next == ans[0]) break;  
        ans.push_back(next);
        nums = next;
    }

    return ans;
}

};