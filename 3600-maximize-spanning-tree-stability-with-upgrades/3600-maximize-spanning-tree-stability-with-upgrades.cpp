#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int find(vector<int>& parent, int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }

    bool unity(vector<int>& parent, int a, int b){
        int pa = find(parent, a);
        int pb = find(parent, b);

        if(pa == pb) return false;

        parent[pa] = pb;
        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
            if(a[3] != b[3]) return a[3] > b[3];
            return a[2] > b[2]; 
        });

        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;

        vector<pair<int,int>> mst;

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int s = e[2];
            int must = e[3];

            if(!unity(parent, u, v)){
                if(must == 1) return -1;
            }
            else{
                mst.push_back({s, must});
            }
        }

      
        if(mst.size() != n-1) return -1;

        sort(mst.begin(), mst.end());

        for(int i = 0; i < min(k, (int)mst.size()); i++){
            if(mst[i].second != 1){
                mst[i].first *= 2;
            }
        }

        sort(mst.begin(), mst.end());

        return mst[0].first;
    }
};