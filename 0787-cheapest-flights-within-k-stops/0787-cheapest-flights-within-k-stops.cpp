class Solution {
public:
    typedef tuple<int,int,int> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto f:flights){
            int i = f[0];
            int j = f[1];
            int p = f[2];
            adj[i].push_back({j,p});
        }
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<int>dist (n,INT_MAX);
        pq.push({0,0,src});
        dist[src]=0;
        while(!pq.empty()){
            auto [m,d,s]=pq.top();
            pq.pop();
            if(m>k) continue;
            for(auto [x,y]:adj[s]){
                cout<<d+y<<" "<<" "<<m+1<<" "<<x<<endl;
               if(dist[x]>d+y){
                dist[x]= d+y;
                pq.push({m+1,dist[x],x});
               }
            } 
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];

    }
};