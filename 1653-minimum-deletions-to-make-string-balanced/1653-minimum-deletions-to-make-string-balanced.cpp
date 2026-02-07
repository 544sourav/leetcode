class Solution {
public:
    int minimumDeletions(string s) {
        // int bCount = 0;
        // int deletions = 0;

        // for (char c : s) {
        //     if (c == 'b') {
        //         bCount++;
        //     } else { 
        //         deletions = min(deletions + 1, bCount);
        //     }
        // }
        // return deletions;
        int cnta =0;
        int cntb =0;
        for(auto x:s){
            if(x =='a')cnta++;
        }
        int mini = cnta;
        for(auto x:s){
            if(x=='a')cnta--;
            else cntb++;
            mini = min(cnta+cntb ,mini);
        }
        return mini;

    }
};
