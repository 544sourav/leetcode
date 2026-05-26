class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(node==parent[node]) return node;

        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u,int v){
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu==pv) return;

        if(size[pu] < size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        DSU dsu(n*m);

        vector<pair<int,int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]=='0') continue;

                for(auto [dx,dy] : dir){

                    int ni = i + dx;
                    int nj = j + dy;

                    if(ni>=0 && ni<n && nj>=0 && nj<m
                       && grid[ni][nj]=='1'){

                        int u = i*m + j;
                        int v = ni*m + nj;

                        dsu.unionBySize(u,v);
                    }
                }
            }
        }

        unordered_set<int> st;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]=='1'){
                    int node = i*m + j;
                    st.insert(dsu.findUPar(node));
                }
            }
        }

        return st.size();
    }
};