class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j =1;
        int n =nums.size();
        vector<int>ans;
        for(auto x:nums){
            if(x==j){
                j++;
            }
            else if(x==j-1)continue;
            else{
               while(j!=x){
                ans.push_back(j);
                j++;
               }
               j++;
            }
        }
        if(j<=n){
            while(j<=n){
                ans.push_back(j);
                j++;
            }
        }
        return ans;
    }
};