class Solution {
public:
    bool dfs(int i,vector<vector<int>>& g,vector<int> &visit, vector<int>&path ){
        visit[i]=1;
        path[i]=1;
        for(auto it :g[i]){
            
                if(!visit[it]){
                    if(dfs(it,g,visit,path)==true){
                        return true;
                    }
                }
                else if(path[it]==true) return true;
            
        }
        path[i]=0;
        return false;


    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> visit(n,0);
        vector<int> path(n,0);
        vector<int> nocycle;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(i,g,visit,path);
            }
        }
        for(int i=0;i<n;i++){
            if(!path[i]){
                nocycle.push_back(i);
            }
        }
        return nocycle;
    }
};