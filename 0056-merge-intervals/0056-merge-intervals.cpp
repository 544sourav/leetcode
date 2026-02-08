class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1)return intervals;
        sort(intervals.begin(),intervals.end());
        int prevx = intervals[0][0];
        int prevy = intervals[0][1];
        vector<vector<int>>ans;
        for(auto v:intervals){
            int curx = v[0];
            int cury = v[1];
            if(curx<=prevy){
               if(cury>prevy) prevy = cury;
            }
            else {
                ans.push_back({prevx,prevy});
                prevx=curx;
                prevy=cury;
            }
        }
        ans.push_back({prevx,prevy});
        return ans;
    }
};