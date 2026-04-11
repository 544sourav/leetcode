class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n<3)return -1;
        vector<pair<int,int>>pv;
        for(int i=0;i<n;i++){
            pv.push_back({nums[i],i});
        }
        sort(pv.begin(),pv.end());
        int dist =INT_MAX;
        for(int i=0;i<=n-3;i++){
            int x = pv[i].first;
            int y = pv[i+1].first;
            int z = pv[i+2].first;
            if(x==y && y==z){
                int temp = abs(pv[i].second - pv[i+1].second) +  abs(pv[i+1].second - pv[i+2].second) +  abs(pv[i].second - pv[i+2].second);
                dist = min(temp,dist);
            }
        }
        return dist == INT_MAX ? -1:dist;
    }
};