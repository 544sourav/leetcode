class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[i]>height[st.top()]){
                auto cur =st.top();
                st.pop();
                if(st.empty()) break;
                int h= min(height[i],height[st.top()]) -height[cur];
                ans+= (i-st.top()-1)*h;

            }
            st.push(i);
        }
        return ans;
    }
};