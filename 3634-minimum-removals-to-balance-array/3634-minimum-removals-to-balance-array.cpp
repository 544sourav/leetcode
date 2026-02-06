class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        // int mini = INT_MAX;
        int maxi = INT_MIN;
        sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++){
        //     long long x = 1LL* nums[i]*k;
        //     int idx = upper_bound(nums.begin(),nums.end(),x)-nums.begin();
        //     // cout<<idx<<endl;
        //      mini = min((i+(n-idx)),mini);
        // }
        int left =0;
        for(int right =0;right<n;right++){

           while ((long long)nums[right] > (long long)k * nums[left]) {
                left++;
            }
            maxi = max(maxi,right-left+1);
        }
        return n-maxi;
    }
};