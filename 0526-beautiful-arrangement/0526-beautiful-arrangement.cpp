class Solution {
public:
    vector<bool>seen;
    int res=0;
    int backtrack(int n,int idx){
        if(idx>n) return res++;
        for(int i=1;i<=n;i++){
            if(!seen[i] && (idx%i==0 || i%idx==0)){
                seen[i]=true;
                backtrack(n,idx+1);
                seen[i]=false;
            }
        }
        return res;
    };
    int countArrangement(int n) {
        seen.resize(n+1,false);
        return backtrack(n,1);
    }
};