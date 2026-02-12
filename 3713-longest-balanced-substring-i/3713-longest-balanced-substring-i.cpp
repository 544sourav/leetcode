class Solution {
public:
    int longestBalanced(string s) {
        int maxi =0;
        for (int i=0;i<s.size();i++){
            vector<int>count(26,0);
            for(int j=i;j<s.size();j++){
                count[s[j]-'a']++;
                bool flag =true;
                int prevcount = count[s[j]-'a'];
                for(int k=0;k<26;k++){
                    if(count[k]!=0 && count[k]!=prevcount){
                        flag = false;
                        break;
                    }
                }
                if(flag)maxi = max(maxi,j-i+1);
            }   
        }
        return maxi;
    }
};