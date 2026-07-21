class Solution {
public:
    void solve(vector<vector<char>>& b) {
        int n = b.size();
        int m = b[0].size();
        vector<vector<bool>> s(n,vector<bool>(m,false));
        vector<vector<bool>> visit(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||j==0||i ==n-1 ||j==m-1)&&b[i][j]=='O'){
                    s[i][j]=true;
                    visit[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            auto[x,y] = q.front();
            cout<<x<<"->"<<y<<endl;
            q.pop();
            for(auto [dx,dy]:dir){
                int nx = x+dx;
                int ny = y+dy;
                cout<<nx<<" "<<ny<<endl;
                if(nx>=0&& ny>=0 && nx<n && ny<m && !visit[nx][ny] && b[nx][ny]=='O'){
                    cout<<nx<<" "<<ny<<endl;
                    s[nx][ny]=true;
                    visit[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]=='O' && s[i][j]==false){
                    cout<<s[i][j]<<endl;
                    b[i][j]='X';
                }
            }
        }


    }
};