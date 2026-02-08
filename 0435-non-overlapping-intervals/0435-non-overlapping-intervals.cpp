class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& a) {
            int n = a.size();
            sort(a.begin(), a.end());

            int c = 0;
            int i = 0;

            for (int j = 1; j < n; j++) {
                if (a[i][1] > a[j][0]) {   
                    c++;
                    if (a[i][1] > a[j][1]) {
                        i = j; 
                    }
                } else {
                    i = j;
                }
            }
            return c;
        }

};