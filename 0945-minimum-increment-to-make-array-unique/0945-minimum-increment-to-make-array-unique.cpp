class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        mp[nums[0]]=1;
        int step=0;
        for(int i=1;i<nums.size();i++){
            if(mp.count(nums[i])){
                int inc = nums[i-1]-nums[i]+1;
                nums[i]+=inc;
                step+=inc;
            }
            mp[nums[i]]=1;
        }
        return step;
    }

};