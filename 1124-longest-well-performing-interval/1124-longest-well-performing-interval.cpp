class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> first;
        int prefix = 0;
        int ans = 0;

        for (int i = 0; i < hours.size(); i++) {

            if (hours[i] > 8)
                prefix++;
            else
                prefix--;

            if (prefix > 0)
                ans = i + 1;
            else {
                if (!first.count(prefix))
                    first[prefix] = i;

                if (first.count(prefix - 1))
                    ans = max(ans, i - first[prefix - 1]);
            }
        }

        return ans;
    }
};