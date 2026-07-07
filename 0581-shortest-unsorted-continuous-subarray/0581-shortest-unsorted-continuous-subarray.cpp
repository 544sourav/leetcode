class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       int s =INT_MAX;
       int e =INT_MIN;
       stack<int>st;
       for(int i=0;i<nums.size();i++){
        while(!st.empty() && nums[st.top()]>nums[i]){
            s= min(s,st.top());
            st.pop();
        }
        st.push(i);
       }
       while(!st.empty())st.pop();
       for(int i=nums.size()-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]<nums[i]){
            e= max(e,st.top());
            st.pop();
        }
        st.push(i);
       }
        if(s==INT_MAX && e==INT_MIN)return 0;
        return e-s+1;
        
    }
};