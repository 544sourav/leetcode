class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(n<m)return -1;
        for(int i=m-1;i<n;i++){
            cout<<"inside";
            if(haystack.substr(i-m+1,m)==needle)return i-m+1 ;
        }
        return -1;
    }
};