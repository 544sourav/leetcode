class Solution {
public:
    vector<pair<int,int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

    int n,m;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(grid[i][j]=='0')return;
        grid[i][j]='0';
        for(auto [x,y]:dir){
            int nx = x+i;
            int ny = y+j;
            if(nx>=0 && nx<n && ny >=0 && ny<m && grid[nx][ny]!='0'){
                // grid[nx][ny]='0';
                dfs(grid,nx,ny);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
         n = grid.size();
         m = grid[0].size();
         int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    // grid[i][j]='0';
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};