class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> newIntervals;
        newIntervals.push_back(intervals[0]);
        int n = intervals.size();
        int j=0;
        for(int i=1;i<n;i++){
            if(newIntervals[j][1]>=intervals[i][0]){
                if(newIntervals[j][1]<intervals[i][1]) newIntervals[j][1]=intervals[i][1];
            }
            else{
                newIntervals.push_back(intervals[i]);
                j++;
            }
        }
        return newIntervals;

    }
};