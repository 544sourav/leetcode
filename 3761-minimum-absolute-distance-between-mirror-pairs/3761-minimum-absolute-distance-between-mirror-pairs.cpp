class Solution {
public:
    int rev(int n){
        int x = 0;
        while(n > 0){
            x = x * 10 + (n % 10);
            n /= 10;
        }
        return x;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();


        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        int mini = INT_MAX;

        for(int i = 0; i < n; i++){
            int x = rev(nums[i]);

            if(mp.find(x) == mp.end()) continue;

            vector<int>& a = mp[x];

            int s = i;

            while(true){
                auto lb = lower_bound(a.begin(), a.end(), s);

                if(lb == a.end()) break;

                int j = *lb;

                if(j == i){
                    s = j + 1; 
                } else {
                    mini = min(mini, j - i);
                    break;
                }
            }
        }

        return (mini == INT_MAX) ? -1 : mini;
    }
};
