class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nge(n, n);   
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if (!st.empty()) nge[i] = st.top();
            st.push(i);
        }

        // for(auto x:nge) cout<<x<<" ";
        // cout<<endl;
        vector<int> ans;
        int j = 0;
        for (int i = 0; i <= n - k; i++) {
            if (j < i) j = i; 

            
            while (nge[j] < i + k)
                j = nge[j];

            ans.push_back(nums[j]);
        }

        return ans;
    }
};
