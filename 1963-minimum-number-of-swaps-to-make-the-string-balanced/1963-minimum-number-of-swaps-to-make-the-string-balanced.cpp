class Solution {
public:
    int minSwaps(string s) {
        int n =s.size();
        int b =0,swaps = 0 , j=n-1;
        for(int i=0;i<n;i++){
            if(s[i]=='[')b++;
            else b--;
            if(b<0){
                while(i<j && s[j]!=']')j--;
                swap(s[i],s[j]);
                swaps++;
                b=1;
            }
        }
        return swaps;
    }
};