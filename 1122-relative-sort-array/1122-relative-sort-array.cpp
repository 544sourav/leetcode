class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for(auto x:arr1){
            mp[x]++;
        }
        int i=0;
        for(auto x:arr2){
            int fre = mp[x];
            mp.erase(x);
            while(fre>0){
                arr1[i]=x;
                i++;
                fre--;
            }
        }
        int j=i;
        for(auto [x,y]:mp){
            while(y>0){
                arr1[i]=x;
                i++;
                y--;
            }
        }
        sort(arr1.begin()+j,arr1.end());
        return arr1;
    }
};