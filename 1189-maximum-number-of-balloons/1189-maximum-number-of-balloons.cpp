class Solution {
public:
    unordered_map<char, int> b = {
        {'b', 1},
        {'a', 1},
        {'l', 2},
        {'o', 2},
        {'n', 1}
    };
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char,int> mp;
        for(auto x:text){
            mp[x]++;
        }
        int mini = INT_MAX;
        for(auto [x,y]:mp){
            if(b.find(x)!=b.end()){
                int req = b[x];
                mini = min(mini,y/req);
                b.erase(x);
            }
        }
        if(b.size()>0)return 0;
        return mini;
    }
};