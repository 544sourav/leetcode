class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int i = 0, j = tokens.size() - 1;
        int cur = 0, maxi = 0;

        while (i <= j) {
            if (tokens[i] <= power) {
                power -= tokens[i];
                cur++;
                maxi = max(maxi, cur);
                i++;
            }
            else if (cur > 0) {
                power += tokens[j];
                cur--;
                j--;
            }
            else {
                break;   
            }
        }

        return maxi;
    }
};