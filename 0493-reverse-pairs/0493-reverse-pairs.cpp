class Solution {
public:
    int cnt = 0;

    void countPairs(vector<int>& left, vector<int>& right) {
        int j = 0;
        for(int i = 0; i < left.size(); i++) {
            while(j < right.size() && (long long)left[i] > 2LL * right[j]) {
                j++;
            }
            cnt += j;
        }
    }

    vector<int> merge(vector<int>& left, vector<int>& right) {
       
        countPairs(left, right);

  
        int i = 0, j = 0;
        vector<int> ans;
        while(i < left.size() && j < right.size()) {
            if(left[i] <= right[j]) ans.push_back(left[i++]);
            else ans.push_back(right[j++]);
        }
        while(i < left.size()) ans.push_back(left[i++]);
        while(j < right.size()) ans.push_back(right[j++]);

        return ans;
    }

    vector<int> mergesort(vector<int>& nums, int l, int r) {
        if(l == r) return vector<int>{nums[l]};
        int mid = (l + r) / 2;

        vector<int> left = mergesort(nums, l, mid);
        vector<int> right = mergesort(nums, mid + 1, r);

        return merge(left, right);
    }

    int reversePairs(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return cnt;
    }
};
