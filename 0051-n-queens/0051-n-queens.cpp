class Solution {
public:
    bool safe(int n,vector<string>&nq,int row,int col){
        for(int i=0;i<n;i++){
            if(nq[i][col]=='Q')return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;j--,i--){
            if(nq[i][j]=='Q')return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(nq[i][j]=='Q')return false;
        }
        return true;
    }
    void solve(int n, vector<vector<string>>&ans,vector<string>&nq,int row){
        if(row==n){
            ans.push_back(nq);
            return;
        }
        for(int i=0;i<n;i++){
            if(safe(n,nq,row,i)){
                nq[row][i]='Q';
                solve(n,ans,nq,row+1);
                nq[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>nq(n,string(n,'.'));
        solve(n,ans,nq,0);
        return ans;

    }
};