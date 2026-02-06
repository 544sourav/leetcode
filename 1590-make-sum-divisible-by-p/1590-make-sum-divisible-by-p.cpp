class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       
        int n = nums.size();
        vector<int> sum(n);
        
        long long total = 0;
        for(int x : nums) total += x;
        int target = total % p;      
        if(target == 0) return 0;

        int curr = 0;
        int mini = INT_MAX;
        unordered_map<int,int> prev;
        prev[0] = -1;

        for(int i = 0; i < n; i++){
            curr = (curr +  nums[i])%p;
            
            int need = (curr - target + p) % p;  
            
            if(prev.find(need) != prev.end()){
                mini = min(mini, i - prev[need]);
            }
            
            prev[curr] = i;
        }
        
        return (mini == INT_MAX || mini == n) ? -1 : mini;
    }
};
