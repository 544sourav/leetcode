class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> st ={'a','e','i','o','u'};
        int total =0;
        int maxi =0;
        for(int i=0;i<k;i++){
            if(st.count(s[i]))total++;
        }
        maxi = max(maxi,total);
        int i =0;
        for(int j =k;j<s.size();j++){
            if(st.count(s[j]))total++;
            if(st.count(s[i]))total--;
            i++;
            maxi = max(maxi,total);
        }
        return maxi;

    }
};