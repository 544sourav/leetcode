class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxi = 0;

        for (int x : st) {
            if (st.find(x - 1) == st.end()) { 
                int cnt = 1;
                int cur = x;

                while (st.find(cur + 1) != st.end()) {
                    cur++;
                    cnt++;
                }
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};
