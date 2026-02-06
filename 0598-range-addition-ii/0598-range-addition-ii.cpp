class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minrow =m, mincol =n;
        for(auto v:ops){
            minrow = min(minrow,v[0]);
            mincol = min(mincol,v[1]);
        }
        return minrow*mincol;
        
    }
};