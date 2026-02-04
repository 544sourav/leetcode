class Solution {
public:
    vector<int> constructArray(int n, int k) {

        vector<int> ans;
        
        int i = 1;
        int j = k + 1;
        
        while (i < j) {
            ans.push_back(i); 
            ans.push_back(j); 
            i++;
            j--;
        }
        
        if (i == j) {
            ans.push_back(i);
        }

        for (int m = k + 2; m <= n; m++) {
            ans.push_back(m);
        }
        return ans;
    }
};