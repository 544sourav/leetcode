class Solution {
public:
    typedef tuple<int, int, int> t;
    vector<pair<int,int>> dir {{1,0},{0,1},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<t> q;
        int n  = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j,0});
            }
        }
        int time  =0;
        while(!q.empty()){
            auto [i,j,t] = q.front();
            q.pop();
            time = max(t,time);
            for(auto [x,y]:dir){
                int nx = x+i;
                int ny = y+j;
                if(nx>=0 && nx<n && ny >=0 && ny<m && grid[nx][ny]==1){
                    q.push({nx,ny,t+1});
                    grid[nx][ny] =2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return time;
    }
};