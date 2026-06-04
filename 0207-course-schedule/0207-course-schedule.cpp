class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int>ans;
        vector<int>ind(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<p.size();i++){
                adj[p[i][0]].push_back(p[i][1]);
        }
        for(int i=0;i<n;i++){
            for(auto nbr:adj[i]){
                ind[nbr]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur =q.front();
            q.pop();
            ans.push_back(cur);
            for(auto nbr:adj[cur]){
                ind[nbr]--;
                if(ind[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        int a = ans.size();
        if(a==n) return true;
        return false;
    }
};