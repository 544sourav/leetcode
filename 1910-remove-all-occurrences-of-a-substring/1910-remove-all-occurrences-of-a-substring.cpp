class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m= part.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            st.push(s[i]);
            if(st.top()==part[m-1]){
                string temp;
                int j=m-1;
                while(j>=0 && !st.empty()&& st.top()==part[j]  ){
                    char a  = st.top();
                    st.pop();
                    temp +=a; 
                    j--;
                }
                reverse(temp.begin(),temp.end());
                if(temp == part){
                    continue;
                }
                else{
                    int z = temp.size();
                    int a =0;
                    while(a<z){
                        st.push(temp[a]);
                        a++;
                    }
                }
            }
        }
        string ans;

        while(!st.empty()){
            ans = ans +st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};