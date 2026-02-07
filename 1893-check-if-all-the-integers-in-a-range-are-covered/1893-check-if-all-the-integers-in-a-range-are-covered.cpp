class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(),ranges.end());
        for(auto r:ranges){
            if(left>=r[0] && left <=r[1] && right >= r[0] && right<=r[1])return true;
            else if(left>=r[0] && left <=r[1]){
                left = r[1]+1;
            }
            else if(right>=r[0] && right <=r[1]) right = r[0]-1;
        }
        // cout<<left<< " "<<right<<endl; 
        // if(left>right)return true;
        return false;
    }
};