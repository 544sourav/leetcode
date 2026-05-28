class Solution {
public:
    vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>&image,int i,int j,int color,int st){
        if(image[i][j]!=st)return;
        image[i][j]=color;
        for(auto [x,y]:dir){
            int nx = x+i;
            int ny = y+j;
            if(nx>=0 && ny>=0&& nx<image.size()&&ny<image[0].size() && image[nx][ny]==st){
                dfs(image,nx,ny,color,st);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int st  = image[sr][sc];
        if(st==color)return image;
        dfs(image,sr,sc,color,st);
        return image;

    }
};