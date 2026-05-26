class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int ,int>mpp;
        for(auto c:word){
            mpp[c]++;
        }
        unordered_map<int,int>cnt;
        for(auto c:word){
                if(islower(c)){
                    int x = c+32;
                    int y = c-32;
                    if(mpp.find(x)!=mpp.end()){
                        cnt[abs(x)]++;
                    }
                    else if(mpp.find(y)!=mpp.end()){
                        cnt[abs(y)]++;
                    }
            }
            
        }
        return cnt.size();
    }
};