class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = i + 1;
        }

        int rem = n;
        int i = 0;

        while(rem != 1) {
            int t = k - 1;

            while(t > 0) {
                i %= n;
                if(a[i] == -1) {
                    i++;
                    continue;
                }
                i++;
                t--;
            }

            while(a[i % n] == -1)
                i++;

            i %= n;
            a[i] = -1;
            rem--;
            i++;
        }

        return *max_element(a.begin(), a.end());
    }
};