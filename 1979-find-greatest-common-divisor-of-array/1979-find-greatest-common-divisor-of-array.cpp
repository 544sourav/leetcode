class Solution {
public:
    int gcd ( int g,int s){
        // int g= max(a,b);
        // int s = min(a,b);
        while(s>0){
            int r = g%s;
            g=s;
            s=r;
        }
        return g;
    }
    int findGCD(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        
        return gcd(maxi,mini);
    }
};