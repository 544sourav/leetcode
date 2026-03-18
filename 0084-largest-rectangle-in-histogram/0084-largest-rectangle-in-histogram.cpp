class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();

        vector<int> right(n, n), left(n, -1);
        stack<int> st;

        // Next Smaller Right
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Left
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            maxi = max(maxi, arr[i] * width);
        }

        return maxi;
    }
};