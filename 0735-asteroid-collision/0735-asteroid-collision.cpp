class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<pair<int,int>>st;
        int n = ast.size();
        for(int i=0;i<n;i++){
            int dir = ast[i]/abs(ast[i]);
            int size = abs(ast[i]);
            bool des =false;
            while(!st.empty() && st.top().second == 1 && dir ==-1){
                if(st.top().first > size){
                    des = true;
                    break;
                }
                else if(st.top().first == size){
                    st.pop();
                    des = true;
                    break;
                }
                st.pop();
            }
            if(!des)st.push({size,dir});
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top().first*st.top().second);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};