class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(auto x:s){
            if(!st.empty()){
                if(x>='a' && x<='z'&& toupper(x)==st.top()){
                    st.pop();
                    continue;
                }
                else if(x>='A' && x<='Z' && tolower(x) ==st.top()){
                    st.pop();
                    continue;
                }
            }
            st.push(x);
        }
        string ans= "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};