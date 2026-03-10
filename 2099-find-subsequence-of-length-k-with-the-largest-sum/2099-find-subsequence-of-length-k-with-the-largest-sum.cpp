class Solution {
public:
    static bool comp (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    };
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> temp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        int z = n -k;
        sort(temp.begin()+z,temp.end(),comp);
        vector<int> ans;
        for (int i = z; i < n; ++i) {
            ans.push_back(temp[i].first);
        }

        return ans;
    }
};