class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int m = edges.size();
        int nodes = m + 1;

        vector<vector<int>> adj(nodes + 1);

        for (auto &e : edges) {
            int x = e[0];
            int y = e[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for (int i = 1; i <= nodes; i++) {
            if (adj[i].size() == m)
                return i;
        }

        return -1;
    }
};