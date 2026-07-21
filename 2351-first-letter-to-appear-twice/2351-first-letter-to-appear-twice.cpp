class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> fre(26, 0);

        for(auto x : s) {
            int i = x - 'a';
            fre[i]++;

            if(fre[i] == 2) {
                return char('a' + i);
            }
        }

        return '\0'; 
    }
};