class Solution {
public:
    bool judgeCircle(string moves) {
        int v =0;
        int h =0;
        for(auto x:moves){
            if(x=='U')v++;
            else if(x=='D')v--;
            else if(x=='L')h++;
            else if(x=='R')h--;
        }
        return v == 0 && h == 0;
    }
};