class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool>&visited,int idx){
        visited[idx]=true;
        for(int i=0;i<isConnected.size();i++){
            if(visited[i]==false && isConnected[idx][i]==1){
                dfs(isConnected,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(),0);
        int cnt=0;
        for(int i=0;i<isConnected.size();i++){
            if(visited[i]==false){
                cnt++;
                dfs(isConnected,visited,i);
            }
        }
        return cnt;
    }

};