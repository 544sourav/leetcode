class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = k % n;
        if (k == 0) return true;

        vector<vector<int>> ans = mat;

        for (int i = 0; i < m; i++) {  
            vector<int>& temp = ans[i];

            if (i % 2 == 0) {
         
                reverse(temp.begin(), temp.end());
                reverse(temp.begin(), temp.end() - k);
                reverse(temp.end() - k, temp.end());
            } else {
              
                reverse(temp.begin(), temp.end());
                reverse(temp.begin(), temp.begin() + k);
                reverse(temp.begin() + k, temp.end());
            }
        }

        return ans == mat;
    }
};