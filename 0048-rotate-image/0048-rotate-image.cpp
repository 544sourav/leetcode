class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n= mat.size();

        for(int i=0;i<n/2;i++){
            for(int j=0;j<(n+1)/2;j++){
                int a,b,c,d;
                a = mat[i][j];
                b = mat[j][n-1-i];
                c = mat[n-1-i][n-1-j];
                d = mat[n-1-j][i];
                mat[i][j] = d;
                mat[j][n-1-i]= a;
                mat[n-1-i][n-1-j]= b;
                mat[n-1-j][i]=c;
            }
        }

    }
};