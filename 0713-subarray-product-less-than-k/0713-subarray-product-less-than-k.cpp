class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k <= 1) return 0;

        int cnt = 0;
        int i = 0;
        long long pro = 1;

        for(int j = 0; j < nums.size(); j++) {

            pro *= nums[j];

            while(pro >= k) {
                pro /= nums[i];
                i++;
            }

            cnt += (j - i + 1);
        }

        return cnt;
    }
};