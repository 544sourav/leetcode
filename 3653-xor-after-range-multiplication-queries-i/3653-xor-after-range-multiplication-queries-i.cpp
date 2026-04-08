class Solution {
public:
    int mod = 1e9 +7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        for(auto q:queries){
            int l = q[0],r=q[1],k=q[2],v=q[3];
            for(int i=l;i<=r;i=i+k){
                long long val =nums[i];
                val = (val*v)%mod;
                nums[i]=(int)val;
            }
        }
        int ans=0;
        for(auto i:nums){
            ans^=i;
        }
        return ans;
    }
};