class Solution {
public:
    bool winnerOfGame(string color) {
        int alice = 0;
        int bob = 0;

        int n = color.size();

        for(int i = 0; i < n; ) {
            int j = i;

            while(j < n && color[j] == color[i]) {
                j++;
            }

            int len = j - i;

            if(color[i] == 'A') {
                alice += max(0, len - 2);
            } 
            else {
                bob += max(0, len - 2);
            }

            i = j;
        }

        return alice > bob;
    }
};