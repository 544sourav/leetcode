class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }
        vector<int>fre;
        for(auto [x,y]:mp){
            fre.push_back(y);
        }
        sort(fre.rbegin(),fre.rend());
        int maxi = fre[0]+1;
        int remove =0;
        for(auto x:fre){
            if(x<maxi){
                maxi = x;
            }
            else if(x>=maxi && maxi!=0 ){
                maxi--;
                remove += x-maxi;
            }
            else if(maxi ==0){
                remove += x;
            }
            
        }
        return remove;
    }
};