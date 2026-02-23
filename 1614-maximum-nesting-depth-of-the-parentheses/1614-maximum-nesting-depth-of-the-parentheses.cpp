class Solution {
public:
    int maxDepth(string s) {
        int maxi =INT_MIN;
        int cnt =0;
        for(auto ch:s){
            if(ch=='('){
                cnt++;
            }
            else if(ch==')' &&cnt!=0){
                cnt--;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};